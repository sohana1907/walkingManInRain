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

void drawTree(int xOffset) {
    // Draw trunk
    line(207 + xOffset, 320, 207 + xOffset, 380);
    line(240 + xOffset, 320, 240 + xOffset, 380);

    // Draw leaves
    ellipse(200 + xOffset, 300, 90, 280, 25, 30);
    ellipse(186 + xOffset, 270, 60, 240, 25, 30);
    ellipse(190 + xOffset, 242, 40, 200, 29, 30);
    ellipse(220 + xOffset, 217, 20, 170, 29, 30);
    ellipse(250 + xOffset, 217, 0, 120, 29, 30);
    ellipse(260 + xOffset, 227, 310, 60, 35, 30);
    ellipse(274 + xOffset, 250, 280, 50, 35, 30);
    ellipse(270 + xOffset, 280, 260, 22, 35, 30);
    ellipse(243 + xOffset, 300, 270, 340, 35, 30);
}

int main() {
    int gd = DETECT, gm, i, d = 0, x = 50, y = 340, z = 50, shouldMove = 1;
    int rx, ry;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Set random seed
    srand(time(NULL));

    while (!kbhit()) {
        cleardevice();

        // Move cloud
        drawCloud(z, cloudY);
        z = (z + cloudSpeed) % (getmaxx() - 100); // Move the cloud position
        line(0, 382, getmaxx(), 382);
        line(0, 450, getmaxx(), 450);

        // Draw walking man
        displayMan(x, 340);

        // Draw tree
        drawTree(-200); // Move the tree to the left side of the screen

        // Right side elements
        rectangle(200, 330, 430, 450);
        rectangle(230, 444, 295, 450);
        rectangle(235, 355, 290, 444);
        circle(244, 399, 3);
        rectangle(340, 348, 410, 400);
        rectangle(345, 353, 405, 395);
        line(375, 353, 375, 395);
        line(130, 249, 426, 249);
        line(430, 330, 445, 330);
        line(445, 330, 426, 249);
        rectangle(350, 235, 380, 249);
        rectangle(346, 230, 384, 235);

        // Left side elements
        line(200, 310, 200, 450);
        line(40, 310, 40, 450);
        line(30, 316, 120, 250);
        line(210, 316, 120, 250);
        line(30, 307, 120, 241);
        line(210, 307, 120, 241);
        line(30, 307, 30, 316);
        line(210, 307, 210, 316);
        rectangle(70, 350, 170, 400);
        rectangle(75, 355, 165, 395);
        line(105, 355, 105, 395);
        line(135, 355, 135, 395);
        rectangle(100, 290, 140, 320);
        line(120, 290, 120, 320);
        line(100, 305, 140, 305);

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
