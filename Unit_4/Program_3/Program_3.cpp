#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// Structure to hold image metadata
struct ImageMetadata {
    int width;
    int height;
    char format[10];
};

int main() {
    // === Step 1: Create Image Metadata Records ===
    ImageMetadata image1{1920, 1080, "PNG"};
    ImageMetadata image2{1280, 720, "JPEG"};
    ImageMetadata image3{3840, 2160, "PNG"};

    // === Step 2: Write Binary Data to File ===
    ofstream output("images.bin", ios::binary);
    
    if (!output) {
        cerr << "Unable to open binary file for writing." << endl;
        return 1;
    }

    output.write(reinterpret_cast<const char*>(&image1), sizeof(ImageMetadata));
    output.write(reinterpret_cast<const char*>(&image2), sizeof(ImageMetadata));
    output.write(reinterpret_cast<const char*>(&image3), sizeof(ImageMetadata));
    
    output.close();

    // === Step 3: Read Binary Data from File ===
    ifstream input("images.bin", ios::binary);
    
    if (!input) {
        cerr << "Unable to open binary file for reading." << endl;
        return 1;
    }

    ImageMetadata item{};
    int recordNo = 1;

    cout << "=== Image Metadata ===" << endl;
    
    while (input.read(reinterpret_cast<char*>(&item), sizeof(ImageMetadata))) {
        cout << "Record " << recordNo++ << ": "
             << item.width << " x " << item.height
             << " | " << item.format << endl;
    }

    input.close();

    return 0;
}