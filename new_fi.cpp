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

        // Move clouds
        drawCloud(z, cloudY);
        drawCloud(z + 200, cloudY + 50); // Add another cloud
        z = (z + cloudSpeed) % (getmaxx() - 100); // Move the first cloud position
        line(0, 382, getmaxx(), 382);
        line(0, 450, getmaxx(), 450);

        // Draw walking man
        displayMan(x, 340);

        // Draw trees
        drawTree(-200); // Move the left tree to the left side of the screen
        drawTree(780);  // Add a tree to the right side of the screen
        drawTree(320);   // Move another tree more to the right side of the screen


// Right side elements
rectangle(280, 260, 460, 380); // Adjusted coordinates for moving the house slightly more to the right
rectangle(310, 374, 375, 380); // Adjusted coordinates for moving the house slightly more to the right
rectangle(400, 278, 450, 330); // Adjusted coordinates for moving the house slightly more to the right
circle(314, 329, 2); // Adjusted coordinates for moving the house slightly more to the right
rectangle(405, 283, 445, 325); // Adjusted coordinates for moving the house slightly more to the right
line(425, 283, 425, 325); // Adjusted coordinates for moving the house slightly more to the right
line(235, 179, 446, 179); // Adjusted coordinates for moving the house slightly more to the right
line(450, 260, 465, 260); // Adjusted coordinates for moving the house slightly more to the right
line(465, 260, 446, 179); // Adjusted coordinates for moving the house slightly more to the right
rectangle(420, 165, 440, 179); // Adjusted coordinates for moving the house slightly more to the right
rectangle(416, 160, 444, 165); // Adjusted coordinates for moving the house slightly more to the right

// Draw the door
rectangle(310, 290, 375, 380); // Adjusted coordinates to create the door

// Left side elements
line(280, 210, 280, 370); // Adjusted coordinates for moving the house slightly more to the right
line(120, 230, 120, 383); // Adjusted coordinates for moving the house slightly more to the right
line(110, 236, 200, 170); // Adjusted coordinates for moving the house slightly more to the right
line(330, 236, 200, 170); // Adjusted coordinates for moving the house slightly more to the right
line(110, 227, 200, 161); // Adjusted coordinates for moving the house slightly more to the right
line(330, 227, 200, 161); // Adjusted coordinates for moving the house slightly more to the right
line(110, 227, 110, 236); // Adjusted coordinates for moving the house slightly more to the right
line(330, 227, 330, 236); // Adjusted coordinates for moving the house slightly more to the right
rectangle(150, 270, 230, 320); // Adjusted coordinates for moving the house slightly more to the right
rectangle(155, 275, 225, 315); // Adjusted coordinates for moving the house slightly more to the right
line(185, 275, 185, 315); // Adjusted coordinates for moving the house slightly more to the right
line(215, 275, 215, 315); // Adjusted coordinates for moving the house slightly more to the right
rectangle(170, 210, 210, 240); // Adjusted coordinates for moving the house slightly more to the right
line(190, 210, 190, 240); // Adjusted coordinates for moving the house slightly more to the right
line(170, 225, 210, 225); // Adjusted coordinates for moving the house slightly more to the right



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

