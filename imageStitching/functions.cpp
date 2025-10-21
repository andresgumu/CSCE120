#include <cmath>
#include <iostream>
#include <vector>
#include "functions.h"

double error_calculation(const Image& image1,
                         const Corner& image1_corner,
                         const Image& image2,
                         const Corner& image2_corner) {
    // TODO(student): Complete error calculation function.

    // initialize variables
    double totalError = 0.0;

    // get height and width to later check for edge cases
    size_t width1 = image1.size();
    size_t height1 = image1[0].size();
    size_t width2 = image2.size();
    size_t height2 = image2[0].size();

    // distance from bold pixel to edge of neighborhood
    int dist_edge = ERROR_NEIGHBORHOOD_SIZE / 2;

    // check if neighborhood is valid (doesn't go out of range of image)
    if (image1_corner.x < static_cast<size_t>(dist_edge) || // if x coord. goes past left edge
        image1_corner.x >= (width1 - dist_edge) || // if x coord. goes past the right edge
        image1_corner.y < static_cast<size_t>(dist_edge) || // same logic, just top and bottom now
        image1_corner.y >= (height1 - dist_edge)) {
            return INFINITY;
        }

    // check for correct bounds with second image as well (same logic, different variable)
    if (image2_corner.x < static_cast<size_t>(dist_edge) ||
        image2_corner.x >= (width2 - dist_edge) ||
        image2_corner.y < static_cast<size_t>(dist_edge) ||
        image2_corner.y >= (height2 - dist_edge)) {
            return INFINITY;
        }

        // iterate through entire neighborhood grid and perform pg. 9 calculations
        for (int y = (-1 * dist_edge); y <= dist_edge; y++){ // goes from negative (left) to positive (right) edge
            for (int x = (-1 * dist_edge); x <= dist_edge; x++){ // iterates through the values
                // use references here as each call might take a long time (for large images)
                const Pixel& pixel_1 = image1.at(image1_corner.x + x).at(image1_corner.y + y); 
                const Pixel& pixel_2 = image2.at(image2_corner.x + x).at(image2_corner.y + y);

                // using references, calculate each difference pertaining to the color and add to totalError

                // perform subtraction
                double red = static_cast<double>(pixel_1.red) - static_cast<double>(pixel_2.red);
                double green = static_cast<double>(pixel_1.green) - static_cast<double>(pixel_2.green);
                double blue = static_cast<double>(pixel_1.blue) - static_cast<double>(pixel_2.blue);


                // add the square of each result above to totalError
                totalError += pow(red, 2) + pow(green, 2) + pow(blue, 2); // used cmath

            }

        }

    return totalError;
}

std::vector<CornerPair> match_corners(const Image& image1,
                                      const std::vector<Corner>& image1_corner,
                                      const Image& image2,
                                      const std::vector<Corner>& image2_corner) {
    // TODO(student): Complete key points matching algorithm

     // get number of corners for each image and width
    size_t width1 = image1.size();
    size_t numCorners1 = image1_corner.size();

    size_t width2 = image2.size();
    size_t numCorners2 = image2_corner.size();

    // store errors in error matrix shown in doc (2d vector)
    std::vector<std::vector<double>> error_matrix(numCorners1, std::vector<double>(numCorners2)); // rows are for image1 corners, columns for image2 corners
    
    //iterate through size of error_matrix

    for (size_t i = 0; i < numCorners1; i++){
        for (size_t j = 0; j < numCorners2; j++){
            // same logic as last function (utilize references)
            const Corner& c1 = image1_corner[i];
            const Corner& c2 = image2_corner[j];

            // booleans used as flags to check if corner pair is valid
            bool isInRightHalf1 = (c1.x >= width1 / 2);
            bool isInLeftHalf2 = (c2.x >= width2 / 2);
            bool isClose = (std::abs(static_cast<int>(c1.y) - static_cast<int>(c2.y)) <= 100); // check if c1 and c2 are in the same proximity
            if (isInRightHalf1 && isInLeftHalf2 && isClose){ // if both conditions are met, store into matrix
                error_matrix[i][j] = error_calculation(image1, c1, image2, c2);
            }
            else {
                error_matrix[i][j] = INFINITY; //bad value
            }
        }
    }

    // greedy algorithm

    // --------------initialize variables needed-----------
    std::vector<bool> corner1Matched(numCorners1, false); // none matched yet, so set all to false
    std::vector<bool> corner2Matched(numCorners2, false);

    // vector that will be returned
    std::vector<CornerPair> matchedPairs;


    // --------------search matrix for lowest error---------------
    while(true){
        // reset best minimum score to error value until we get a matched pair
        double bestError = INFINITY;
        // variables to store location of min error pair
        int best_x = -1;
        int best_y = -1; // set to -1 as starting point

        // for loop to iterate through every row of the matrix
        for (size_t i = 0; i < numCorners1; i++){
             // check if there are corners that can't be used again
            if (!corner1Matched[i]){ // executes if there is no matched corner yet
                for (size_t j = 0; j < numCorners2; j++){ 
                    if (!corner2Matched[j] && error_matrix[i][j] < bestError){ // check if conrer for corr. column j is availabe, also if there is a better min error
                        bestError = error_matrix[i][j];
                        best_x = i;
                        best_y = j;
                    }
                }
            }
        }

         // if not found, set equal to INFINITY
        if (bestError == INFINITY){ // if nested for loop executes and finds no min error, break
            break;
        }

        // if found, save into corr. variable
        matchedPairs.push_back({image1_corner[best_x], image2_corner[best_y], bestError});
        
        // update bool vector for the corr. locations
        corner1Matched[best_x] = true;
        corner2Matched[best_y] = true;
    }



    return matchedPairs;
}

void map_coordinates(const Matrix&,
                     size_t,
                     size_t,
                     double&,
                     double&) {
    // TODO(student): Complete map function with homography
}

Image merge_images(const Image&,
                   const Image&,
                   const std::vector<std::vector<double>>&) {
    // TODO(student): Complete merge function.
    return {};
}
