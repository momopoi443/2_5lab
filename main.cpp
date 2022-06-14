
#include <iostream>
#include <fstream>

void reSerializer (const std::string& pathFrom,const std::string& pathTo) {

    std::ifstream fileFrom;
    std::ofstream fileTo;

    fileFrom.open(pathFrom);
    fileTo.open(pathTo);

    if (!fileFrom.is_open()) {

        std::cout << "file form not found" << std::endl;

        return;
    }

    int size = 3;
    std::string buffer[size];
    int counter = 0;

    while(fileFrom >> buffer[counter]) {

        if (counter == 2) {

            if (buffer[size - 1].back() == ',') {

                buffer[size - 1].pop_back();
            }

            fileTo << " " << buffer[size - 1];

            for (int i = 0; i < size - 1; i++) {

                fileTo << " " << buffer[i];
            }

            fileTo << ",";

            counter = 0;
        } else {

            counter++;
        }
    }

    fileFrom.close();
    fileTo.close();
}

int main() {

    std::string pathFrom = "../resources/from.txt";
    std::string pathTo = "../resources/to.txt";

    reSerializer(pathFrom, pathTo);

    return 0;
}
