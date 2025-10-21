#include<cmath>
#include<cstdint>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include "functions.h"

Image load_image(const std::string& filename) {
    // TODO(student): implement image loading

    // -----------check if parameter is valid--------------------

    // if filename is empty
    if (filename.empty()){
        throw std::runtime_error("Invalid filename");
    }

    std::fstream outfile(filename);

    // if the file cannot be opened
    if (!outfile){
        throw std::runtime_error("Failed to open " + filename);
    }

    std::string type = "";
    outfile >> type;

    // if the file type is missing (ie. file is empty)
    if (outfile.fail()){
        throw std::runtime_error("Failed to read type");
    }
    // if the file type is not "P3" or "p3"
    if ((type != "p3") && (type != "P3")){
        throw std::runtime_error("Invalid type " + type);
    }

    // Both dimensions should be positive integers and less than or equal to the
    // maximums defined in functions.h. If either dimension is missing or invalid:
    size_t width = 0; // always positive
    outfile >> width;
    if (outfile.fail()){
        throw std::runtime_error("Invalid dimensions");
    }

    size_t height = 0;
    outfile >> height;

    if (outfile.fail()){
        throw std::runtime_error("Invalid dimensions");
    }

    if((width == 0 || width > MAX_WIDTH) || (height == 0 || height > MAX_HEIGHT)){
        throw std::runtime_error("Invalid dimensions");
    }

    size_t color_value = 0;
    outfile >> color_value;
    if (outfile.fail()){
        throw std::runtime_error("Invalid max color");
    }
    // if max color value is missing or less than 1 or greater than 255
    if (color_value < 1 || color_value > 255){
        throw std::runtime_error("Invalid max color");
    }

    Image image(width, std::vector<Pixel>(height));
    // Each pixel should be 3 (red, green, and blue) non-negative integers less than the
    // max color value. If there is an invalid pixel value:
    for (size_t row = 0; row < height; row++){
        for (size_t col = 0; col < width; col++){
            int r = 0, g = 0, b = 0;

            // check if there is not enough values
            outfile >> r;
            if (outfile.fail()) { 
                throw std::runtime_error("Not enough values");
            }
            outfile >> g;
            if (outfile.fail()) { 
                throw std::runtime_error("Not enough values");
            }
            outfile >> b;
            if (outfile.fail()) { 
                throw std::runtime_error("Not enough values");
            }

            // check for invalid color value
            if ((r < 0 || r > static_cast<int>(color_value)) || (g < 0 || g > static_cast<int>(color_value)) || (b < 0 || b > static_cast<int>(color_value))){
                throw std::runtime_error("Invalid color value");
            }

            // store pixel if valid
            image.at(col).at(row) = {static_cast<u_int8_t>(r), static_cast<u_int8_t>(g), static_cast<u_int8_t>(b)}; // brace initialization to make it easier

        }
    }

    size_t extra_val;
    outfile >> extra_val;
    //if there are too many pixels (read was successful)
    if (!outfile.fail()){
        throw std::runtime_error("Too many values");
    }


    // if everything is valid, return scaled image

    return image;
}

void output_image(const std::string& filename,
                  const Image& image) {
    // TODO(student): implement writing image to file (in row major order)

    // check if parameters are valid

    // if filename is empty
    if (filename.empty()){
        throw std::invalid_argument("Invalid filename");
    }

    // if Image vector is empty
    if (image.empty()){
        throw std::invalid_argument("Invalid image");
    }
    if (image[0].empty()){
        throw std::invalid_argument("Invalid image");

    }

    // open file for writing
    std::ofstream outfile(filename);

    // if output file can't be opened
    if (!outfile){
        throw std::invalid_argument("Failed to open " + filename);
    }


    // otherwise, begin implementing
    // vector Image is in column-major order (image[x][y], x is column, y is row)
    size_t width = image.size(); // how long the row would be (width)
    size_t height = image[0].size(); // how long a column would be (height)
    
    // output preamble
    outfile << "P3\n";
    outfile << width << " " << height << "\n";
    outfile << "255\n";

    // need to iterate through rows first, then columns
    for (size_t y = 0; y < height; y++){
        // iterate through columns 
        for (size_t x = 0; x < width; x++){
            outfile << static_cast<int>(image[x][y].red) << " " << static_cast<int>(image[x][y].green) << " " << static_cast<int>(image[x][y].blue);

            // make sure no space is at the very end of the line (only in between RGB values)
            if (x < width - 1){
                outfile << " ";
            }
        }
        // add newline after each row
        outfile << "\n";
    } 

}

double map_coordinates(size_t source_dimension, // size_t is unsigned (always positive)
                       size_t target_dimension,
                       size_t pixel_coordinate) {
    // TODO(student): implement mapping function.

    // source_dimension must be greater than 0
    // target_dimension must be greater than 1
    if (source_dimension == 0 || target_dimension == 1 || target_dimension == 0){
        throw std::invalid_argument("Invalid dimension");
    }
    // pixel_coordinate must be less than the target_dimension
    if (pixel_coordinate >= target_dimension){
        throw std::invalid_argument("Invalid coordinate");
    }
    

    // if parameters valid, do the mapping
    double source_coordinate = ((static_cast<double>(source_dimension) - 1) / (static_cast<double>(target_dimension) - 1)) * pixel_coordinate;

    return source_coordinate;
}

Pixel bicubic_interpolation(const Image& source_image,
                            double x,
                            double y) {
    // TODO(student): Implement bicubic interpolation

    // check if parameters are valid

    // check if image is empty
    if (source_image.empty()){
        throw std::invalid_argument("Invalid image");
    }
    if (source_image.at(0).empty()){
        throw std::invalid_argument("Invalid image");
    }

    // need to initialize this before i use it in my last check
    size_t width = source_image.size(); // how long the row would be (width)
    size_t height = source_image[0].size(); // how long a column would be (height)

    // check if x or y coordinate is invalid (ie. out of bounds of source image)
    if (x < 0 || x >= static_cast<double>(width) || y < 0 || y >= static_cast<double>(height)){
        throw std::invalid_argument("Invalid coordinate");
    }

    // otherwise, implement function

    // initialize variables 
    int x1 = floor(x) - 1;
    int y1 = floor(y) - 1;
    int x_coord = 0;
    int y_coord = 0;

    // navigate through 4x4 grid by using (int(x) - 1, int(x), int(x) + 1, int(x) + 2 and same for y)
    // four calls to bicubic_pixel (b/c 4x4 grid)

    // initialize vector grid to store pixel values and intermediate pixels
    Image grid(4, std::vector<Pixel>(4));
    std::vector<Pixel> intermediate_pixels(4);

    // nested for loop to iterate through 4x4 grid and populate 2d vector 4x4 grid
    for (int i = 0; i < 4; i++){ // represents rows
        for (int j = 0; j < 4; j++){ // represents columns
            x_coord = x1 + j;
            y_coord = y1 + i;

            // take care of edge cases
            // need to be within width -1 and height -1, as well as be positive
            int corrected_x = std::max(0, x_coord);
            corrected_x = std::min(static_cast<int>(width - 1), corrected_x);

            int corrected_y = std::max(0, y_coord);
            corrected_y = std::min(static_cast<int>(height - 1), corrected_y);

            // get pixel from source image and store into vector
            grid.at(i).at(j) = source_image.at(corrected_x).at(corrected_y);
        }
    }

    // calculate fractional part
    double fractional_x = x - floor(x);
    double fractional_y = y - floor(y);

    // populate second vector with intermediate pixels that will be used in bicubic function
    // will basically hold the blue dots on the hw doc
    for (int k = 0; k < 4; k++){
        intermediate_pixels.at(k) = bicubic_pixel(fractional_x, grid.at(k).at(0), grid.at(k).at(1), grid.at(k).at(2), grid.at(k).at(3));
    }

    Pixel answer = bicubic_pixel(fractional_y, intermediate_pixels.at(0), intermediate_pixels.at(1), intermediate_pixels.at(2), intermediate_pixels.at(3));

    return answer;
}

Image scale_image(const Image& source_image,
                  size_t target_width,
                  size_t target_height) {
    // TODO(student): add loops to calculate scaled images

    // check if parameters are valid
    
    // if image is empty
    if (source_image.empty()){
        throw std::invalid_argument("Invalid image");
    }
    if (source_image.at(0).empty()){
        throw std::invalid_argument("Invalid image");
    }

    // if target dimensions are invalid (start using .at() more)
    if ((target_width >= MAX_WIDTH || target_height >= MAX_HEIGHT) ||(target_width == 0 || target_height == 0)){
        throw std::invalid_argument("Invalid dimension");
    }

    double mapped_x = 0;
    double mapped_y = 0;
    size_t source_width = source_image.size();
    size_t source_height = source_image.at(0).size();
    Image target_image(target_width, std::vector<Pixel>(target_height));

    // otherwise implement function
    for (size_t i = 0; i < target_width; i++){
        for (size_t j = 0; j < target_height; j++){
            mapped_x = map_coordinates(source_width, target_width, i);
            mapped_y = map_coordinates(source_height, target_height, j);
            target_image.at(i).at(j)= bicubic_interpolation(source_image, mapped_x, mapped_y);
        }
    }

    return target_image;
}
