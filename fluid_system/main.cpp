#include <iostream>


class Volume{
public:
    float pressure;
    float volume;
    float beta = 10;

    void update(float Q1, float Q2){
        pressure += 0.001*(beta/volume)*(Q1+Q2);
    }

};

class Drain : public Volume{
public:
    void update(){
        pressure = 0;
    }
};

class orifice{
public:
    float Q = 0;
    int G = 0;
    Volume *A;
    Volume *B;

    void update(){
        Q = G*(A->pressure-B->pressure);
    }

    void toggle_valve(){
         G = !G;
    }
};


int main() {
    std::cout << "Start Simulation" << std::endl;

    Volume V1;
    V1.volume = 100;
    V1.pressure = 1000;

    Volume V2;
    V2.volume = 1;
    V2.pressure = 0;

    Drain D1;
    D1.volume = 0;
    D1.pressure = 0;

    orifice O1;
    O1.A = &V1;
    O1.B = &V2;

    orifice O2;
    O2.A = &V2;
    O2.B = &D1;

    bool E1,E2,E3 = false;

    float t = 0;
    while(t<10){
        if(t>=1.000 and !E1){O1.toggle_valve(); printf("%6.3f: toggle O1\n",t); E1 = true;}
        if(t>=4.000 and !E2){O1.toggle_valve(); printf("%6.3f: toggle O1\n",t); E2 = true;}
        if(t>=8.000 and !E3){O2.toggle_valve(); printf("%6.3f: toggle O2\n",t); E3 = true;}

        O1.update();
        O2.update();
        V1.update(0,-1*O1.Q);
        V2.update(O1.Q,-1*O2.Q);
        D1.update();

        printf("%6.3f: accumulator %.5f cylinder %.5f\n", t, V1.pressure, V2.pressure);
        t += 0.001;
    }

    return 0;
}
