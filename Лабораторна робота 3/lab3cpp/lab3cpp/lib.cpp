#include "lib.h"

cPoint::cPoint(double Ro, int Phi, double Z) {
    this->ro = Ro;
    this->phi = Phi;
    while (phi > 360) { phi -= 360; }
    this->z = Z;
}

cPoint::cPoint(string line) {
    ro = stod(splitCoords(line)[0]);
    phi = stoi(splitCoords(line)[1]);
    while (phi > 360) { phi -= 360; }
    z = stod(splitCoords(line)[2]);
}

cPoint::cPoint(cPoint& pt) {
    this->ro = pt.ro;
    this->phi = pt.phi;
    this->z = pt.z;
}

int cPoint::GetPhi() {
    return phi;
}

double cPoint::GetRo() {
    return ro;
}

double cPoint::GetZ() {
    return z;
}

double cPoint::FindDistance() {
    return sqrt(ro * ro + z * z);
}

cPoint cPoint::operator++ () {
    this->phi++;
    this->phi = (this->phi <= 360) ? this->phi : this->phi - 360;
    return *this;
}

cPoint cPoint::operator+= (double val) {
    this->ro += val;
    return *this;
}

bool operator== (cPoint& one, cPoint& other) {
    return ((one.ro == other.ro) && (one.phi == other.phi) && (one.z == other.z));
}


vector<string> splitCoords(string line) {
    vector<string> coords;
    char sep = ' ';
    line += sep;
    string buffer = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
            if (buffer.length() > 0)
                coords.push_back(buffer);
            buffer = "";
        }
        else
            buffer += line[i];
    }
    return coords;
}
