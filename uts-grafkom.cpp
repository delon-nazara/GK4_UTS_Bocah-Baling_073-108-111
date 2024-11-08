#include <glut.h>

const int width = 640;
const int height = 480;
float theta = 0.0f;
float translateX = -100.0f;

void drawCloud(float x, float y) {
    glColor3f(1.0, 1.0, 1.0); // Warna putih

    // Gambar awan dengan beberapa quads (kotak-kotak kecil)
    glBegin(GL_QUADS); // Awan bagian kiri
    glVertex2f(x - 20, y);
    glVertex2f(x, y);
    glVertex2f(x, y + 10);
    glVertex2f(x - 20, y + 10);
    glEnd();

    glBegin(GL_QUADS); // Awan bagian tengah kiri
    glVertex2f(x, y);
    glVertex2f(x + 20, y);
    glVertex2f(x + 20, y + 10);
    glVertex2f(x, y + 10);
    glEnd();

    glBegin(GL_QUADS); // Awan bagian tengah kanan
    glVertex2f(x + 10, y + 5);
    glVertex2f(x + 30, y + 5);
    glVertex2f(x + 30, y + 15);
    glVertex2f(x + 10, y + 15);
    glEnd();

    glBegin(GL_QUADS); // Awan bagian kanan
    glVertex2f(x + 30, y);
    glVertex2f(x + 50, y);
    glVertex2f(x + 50, y + 10);
    glVertex2f(x + 30, y + 10);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    // Langit (bagian atas layar)
    glColor3f(0.6, 0.9, 1.0); // Warna biru muda untuk langit
    glBegin(GL_QUADS);
    glVertex2f(-100, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 100);
    glVertex2f(-100, 100);
    glEnd();


    //Awan animasi
    glPushMatrix();
    glTranslatef(translateX, 0, 0); // Pindahkan awan ke kanan secara bertahap

    // Gambar awan
    drawCloud(-170, 70);
    drawCloud(-100, 60);
    drawCloud(-40, 40);
    drawCloud(20, 70);
    drawCloud(-80, 60);
    drawCloud(60, 50);
    drawCloud(90, 50);
    drawCloud(145, 70);

    translateX += 0.005;
    glPopMatrix();

    if (translateX > 100) {
        translateX = -100.0f; // Reset posisi ke kiri
    }

    // Pasir (bagian bawah layar)
    glColor3f(0.85, 0.65, 0.4); // Warna krem untuk pasir
    glBegin(GL_QUADS);
    glVertex2f(-100, -100);
    glVertex2f(100, -100);
    glVertex2f(100, 0);
    glVertex2f(-100, 0);
    glEnd();

    // Kepala
    glColor3f(1.0, 0.8, 0.6); // Warna kulit (peach)
    glBegin(GL_QUADS);
    glVertex2f(-10, 60);
    glVertex2f(10, 60);
    glVertex2f(10, 30);
    glVertex2f(-10, 30);
    glEnd();


    // Mata Kiri
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk mata
    glPointSize(5); // Ukuran mata
    glBegin(GL_POINTS);
    glVertex2f(-5, 50);
    glEnd();

    // Mata Kanan
    glBegin(GL_POINTS);
    glVertex2f(5, 50);
    glEnd();

    // Mulut
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk mulut
    glBegin(GL_LINES);
    glVertex2f(-4, 40);
    glVertex2f(4, 40);
    glEnd();

    // Rambut
    glColor3f(0, 0, 0); // Warna hitam
    glBegin(GL_QUADS);
    glVertex2f(-13, 64);
    glVertex2f(10, 60);
    glVertex2f(10, 50);
    glVertex2f(-10, 54);
    glEnd();

    // Tubuh
    glColor3f(0.0, 0.0, 1.0); // Warna biru untuk tubuh
    glBegin(GL_QUADS);
    glVertex2f(-15, 30);
    glVertex2f(15, 30);
    glVertex2f(15, -20);
    glVertex2f(-15, -20);
    glEnd();

    // Singlet
    glColor3f(1.0, 0.8, 0.6); // Warna kulit
    glBegin(GL_TRIANGLES);
    glVertex2f(-5, 30);
    glVertex2f(5, 30);
    glVertex2f(0, 15);
    glEnd();

    // Tangan Kiri
    glColor3f(1.0, 0.8, 0.6); // Warna kulit
    glBegin(GL_QUADS);
    glVertex2f(-20, 30);
    glVertex2f(-15, 30);
    glVertex2f(-15, -10);
    glVertex2f(-20, -10);
    glEnd();

    // Tangan Kanan
    glBegin(GL_QUADS);
    glVertex2f(15, 23);
    glVertex2f(15, 30);
    glVertex2f(50, 30);
    glVertex2f(50, 23);
    glEnd();

    // Kaki Kiri
    glColor3f(0.0, 0.0, 0.0); // Warna hitam untuk kaki
    glBegin(GL_QUADS);
    glVertex2f(-10, -20);
    glVertex2f(-5, -20);
    glVertex2f(-5, -50);
    glVertex2f(-10, -50);
    glEnd();

    // Kaki Kanan
    glBegin(GL_QUADS);
    glVertex2f(5, -20);
    glVertex2f(10, -20);
    glVertex2f(10, -50);
    glVertex2f(5, -50);
    glEnd();

    // Sepatu kanan kiri
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(5, -50);
    glVertex2f(10, -50);
    glVertex2f(10, -60);
    glVertex2f(5, -60);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-10, -50);
    glVertex2f(-5, -50);
    glVertex2f(-5, -60);
    glVertex2f(-10, -60);
    glEnd();

    // batang kincir angin
    glColor3f(0.545, 0.271, 0.074);
    glBegin(GL_QUADS);
    glVertex2f(47, 30);
    glVertex2f(49, 30);
    glVertex2f(49, 49);
    glVertex2f(47, 49);
    glEnd();

    // Kincir angin (di atas batang)
    glPushMatrix();
    glTranslatef(48, 50, 0); // Pindahkan pusat rotasi
    glRotatef(theta, 0, 0, 1);
    glColor3f(0.0, 1.0, 0.0); // Warna kuning untuk kincir angin

    for (int i = 0; i < 4; i++) {
        glRotatef(90, 0, 0, 1); // Putar 90 derajat untuk setiap bilah
        glBegin(GL_TRIANGLES);
        glVertex2f(0, 0);
        glVertex2f(0, 10);
        glVertex2f(10, 10);
        glEnd();
    }

    theta += 0.15;  //BAGUSNYA SIH KALO BELOM JALAN, PERTAMBAHAN THETA NYA 0, TP KALO JALAN, BISA DIBUAT SEKIAN
    glPopMatrix();

    glutPostRedisplay();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100); // Sistem koordinat ortografis
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Karakter Sederhana");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}