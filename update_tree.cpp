#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h> // Added for random seed initialization

const int screenWidth = 800;
const int screenHeight = 600;
const int cloudSpeed = 2;
const int cloudY = 60;

void displayMan(int x, int y) {
    circle(x, y, 10);               // face
    line(x, y + 10, x, y + 30);     // neck
    line(x, y + 30, x - 20, y + 40); // left hand
    line(x, y + 30, x + 20, y + 40); // right hand
    line(x + 20, y + 40, x + 30, y + 30);
    line(x, y + 30, x, y + 70);      // body
    line(x + 30, y + 30, x + 30, y - 90); // umbrella
    pieslice(x + 30, y - 30, 0, 180, 55);
}

void drawCloud(int z, int y) {
    int r = 50;
    setcolor(LIGHTGRAY); // Set cloud color to gray
    arc(z, y, 45, 135, r);
    arc(z + 50, y, 45, 135, r);
    arc(z + 100, y, 45, 135, r);
    arc(z, y, 135, 225, r);
    arc(z + 50, y, 135 + 90, 225 + 90, r);
    arc(z, y, 135 + 90, 225 + 90, r);
    arc(z + 100, y, 135 + 90, 225 + 90, r);
    arc(z + 100, y, 315, 45, r);
}

void drawTree() {
    // Draw trunk
    line(207, 320, 207, 380);
    line(240, 320, 240, 380);

    // Draw leaves
    ellipse(200, 300, 90, 280, 25, 30);
    ellipse(186, 270, 60, 240, 25, 30);
    ellipse(190, 242, 40, 200, 29, 30);
    ellipse(220, 217, 20, 170, 29, 30);
    ellipse(250, 217, 0, 120, 29, 30);
    ellipse(260, 227, 310, 60, 35, 30);
    ellipse(274, 250, 280, 50, 35, 30);
    ellipse(270, 280, 260, 22, 35, 30);
    ellipse(243, 300, 270, 340, 35, 30);
}

int main() {
    int gd = DETECT, gm, i, d = 0, x = 50, y = 340, z = 50, shouldMove = 1;
    int rx, ry;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Set random seed
    srand(time(NULL));

    while (!kbhit()) {
        cleardevice();

        // Draw tree
        drawTree();

        // Draw walking man
        displayMan(x, 340);

        // Move cloud
        drawCloud(z, cloudY);
        z = (z + cloudSpeed) % (getmaxx() - 100); // Move the cloud position
        line(0, 382, getmaxx(), 382);
        line(0, 450, getmaxx(), 450);


        for (i = 0; i < 500; i++) {
            rx = rand() % getmaxx();
            ry = rand() % 439;
             //line(rx - 10, ry + 10, rx, ry);
        }

        // legs
        if (shouldMove) {
            if (d < 20)
                d += 4;
            else
                shouldMove = 0;
            line(x, y + 70, x - d, y + 90);
            line(x, y + 70, x + d, y + 90);
        } else {
            if (d > 0)
                d -= 4;
            else
                shouldMove = 1;
            line(x, y + 70, x - d, y + 90);
            line(x, y + 70, x + d, y + 90);
        }
        delay(200);
        x = (x + 10) % getmaxx();
    }

    getch();
    closegraph();
    return 0;
}
