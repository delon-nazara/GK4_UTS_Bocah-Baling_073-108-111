#include <glut.h>  // Untuk library OpenGL

// Variabel untuk ukuran layar
const int screenWidth = 640;
const int screenHeight = 480;

// Variabel untuk kontrol animasi kincir angin
float windmillRotationAngle = 0.0f;
float windmillRotationSpeed = 0.0f;

// Variabel untuk kontrol posisi awan
float cloudPositionX = -100.0f;

// Variabel untuk kontrol posisi karakter
float characterPosX = 0.0f;
float characterPosY = 0.0f;

// Variabel untuk kontrol animasi lompatan
bool isJumping = false;
float jumpSpeed = 0.1f;
float jumpHeight = 0.0f;

// Variabel untuk kontrol warna baju
float shirtColorR = 0.0f;
float shirtColorG = 0.0f;
float shirtColorB = 1.0f; 

// Fungsi untuk mendapatkan komponen warna secara acak (untuk warna baju)
int getRandomColorComponent() {
    return rand() % 3; // 0 untuk R, 1 untuk G, 2 untuk B
}

// Fungsi untuk menggambar awan
void drawCloud(float x, float y) {
    glColor3f(1.0, 1.0, 1.0); // Warna awan (putih)

    // Awan bagian ujung kiri
    glBegin(GL_QUADS); 
        glVertex2f(x - 20, y);
        glVertex2f(x, y);
        glVertex2f(x, y + 10);
        glVertex2f(x - 20, y + 10);
    glEnd();

    // Awan bagian tengah kiri
    glBegin(GL_QUADS); 
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 10);
        glVertex2f(x, y + 10);
    glEnd();

    // Awan bagian tengah kanan
    glBegin(GL_QUADS);
        glVertex2f(x + 10, y + 5);
        glVertex2f(x + 30, y + 5);
        glVertex2f(x + 30, y + 15);
        glVertex2f(x + 10, y + 15);
    glEnd();

    // Awan bagian ujung kanan
    glBegin(GL_QUADS); 
        glVertex2f(x + 30, y);
        glVertex2f(x + 50, y);
        glVertex2f(x + 50, y + 10);
        glVertex2f(x + 30, y + 10);
    glEnd();
}

// Fungsi untuk menggambar karakter dan baling-baling
void character() {
    glPushMatrix();
    glTranslatef(characterPosX, characterPosY, 0); // Posisi awal karakter

    // Bagian kepala
    glColor3f(1.0, 0.8, 0.6);
    glBegin(GL_QUADS);
        glVertex2f(-10, 60);
        glVertex2f(10, 60);
        glVertex2f(10, 30);
        glVertex2f(-10, 30);
    glEnd();

    // Bagian mata kiri
    glColor3f(0.0, 0.0, 0.0); 
    glPointSize(5); 
    glBegin(GL_POINTS);
        glVertex2f(-5, 50);
    glEnd();

    // Bagian mata kanan
    glBegin(GL_POINTS);
        glVertex2f(5, 50);
    glEnd();

    // Bagian mulut
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_LINES);
        glVertex2f(-4, 40);
        glVertex2f(4, 40);
    glEnd();

    // Bagian rambut
    glColor3f(0, 0, 0); 
    glBegin(GL_QUADS);
        glVertex2f(-13, 64);
        glVertex2f(10, 60);
        glVertex2f(10, 50);
        glVertex2f(-10, 54);
    glEnd();

    // Bagian tubuh (baju)
    glColor3f(shirtColorR, shirtColorG, shirtColorB); // Warna baju (biru default, berubah ketika mouse-scroll)
    glBegin(GL_QUADS);
        glVertex2f(-15, 30);
        glVertex2f(15, 30);
        glVertex2f(15, -20);
        glVertex2f(-15, -20);
    glEnd();

    // Bagian leher
    glColor3f(1.0, 0.8, 0.6);
    glBegin(GL_TRIANGLES);
        glVertex2f(-5, 30);
        glVertex2f(5, 30);
        glVertex2f(0, 15);
    glEnd();

    // Bagian tangan kiri
    glColor3f(1.0, 0.8, 0.6);
    glBegin(GL_QUADS);
        glVertex2f(-20, 30);
        glVertex2f(-15, 30);
        glVertex2f(-15, -10);
        glVertex2f(-20, -10);
    glEnd();

    // Bagian tangan kanan
    glBegin(GL_QUADS);
        glVertex2f(15, 23);
        glVertex2f(15, 30);
        glVertex2f(50, 30);
        glVertex2f(50, 23);
    glEnd();

    // Bagian kaki kiri
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-10, -20);
        glVertex2f(-5, -20);
        glVertex2f(-5, -50);
        glVertex2f(-10, -50);
    glEnd();

    // Bagian kaki kanan
    glBegin(GL_QUADS);
        glVertex2f(5, -20);
        glVertex2f(10, -20);
        glVertex2f(10, -50);
        glVertex2f(5, -50);
    glEnd();

    // Bagian sepatu kanan
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(5, -50);
        glVertex2f(10, -50);
        glVertex2f(10, -60);
        glVertex2f(5, -60);
    glEnd();

    // Bagian sepatu kiri
    glBegin(GL_QUADS);
        glVertex2f(-10, -50);
        glVertex2f(-5, -50);
        glVertex2f(-5, -60);
        glVertex2f(-10, -60);
    glEnd();

    // Bagian batang baling-baling
    glColor3f(0.545, 0.271, 0.074);
    glBegin(GL_QUADS);
        glVertex2f(47, 30);
        glVertex2f(49, 30);
        glVertex2f(49, 49);
        glVertex2f(47, 49);
    glEnd();

    // Bagian baling-baling
    glPushMatrix();
    glTranslatef(48, 50, 0);
    glRotatef(windmillRotationAngle, 0, 0, 1);
    glColor3f(0.0, 1.0, 0.0); 

    // Baling-baling terdiri dari 4 bilah
    for (int i = 0; i < 4; i++) {
        glRotatef(90, 0, 0, 1);
        glBegin(GL_TRIANGLES);
            glVertex2f(0, 0);
            glVertex2f(0, 10);
            glVertex2f(10, 10);
        glEnd();
    }

    // Perbaharui kecepatan baling-baling
    windmillRotationAngle += windmillRotationSpeed;
}

// Fungsi untuk mengontrol keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {

        // Tombol W untuk memindahkan karakter ke atas
        case 'W':
        case 'w':
            if (characterPosY + 10 <= 35)
                characterPosY += 10;
            break;

        // Tombol A untuk memindahkan karakter ke kiri
        case 'A':
        case 'a':
            if (characterPosX - 10 >= -80)
                characterPosX -= 10;
            break;

        // Tombol S untuk memindahkan karakter ke bawah
        case 'S':
        case 's':
            if (characterPosY - 10 >= -40)
                characterPosY -= 10;
            break;

        // Tombol D untuk memindahkan karakter ke kanan
        case 'D':
        case 'd':
            if (characterPosX + 10 <= 45)
                characterPosX += 10;
            break;

        // Tombol Q untuk mempercepat rotasi baling-baling
        case 'Q':
        case 'q':
            windmillRotationSpeed += 0.05f;
            break;

        // Tombol E untuk memperlambat rotasi baling-baling
        case 'E':
        case 'e':
            windmillRotationSpeed -= 0.05f;
            if (windmillRotationSpeed < 0) {
                windmillRotationSpeed = 0;
            }
            break;

        // Tombol R untuk menghentikan rotasi baling-baling
        case 'R':
        case 'r':
            windmillRotationSpeed = 0;
            break;

        // Tombol B untuk mengembalikan warna baju menjadi default (biru)
        case 'B':
        case 'b':
            shirtColorR = 0.0f;
            shirtColorG = 0.0f;
            shirtColorB = 1.0f;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

// Fungsi untuk mengontrol mouse
void mouse(int button, int state, int x, int y) {

    // Tombol kiri mouse untuk membuat karakter melompat
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !isJumping) {
        isJumping = true; 
    } 
    
    // Tombol kanan mouse untuk membuat karakter berpindah tempat ke posisi cursor
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Konversi dari screen-coordinat ke world-coordinat
        float newX = (x / (float)screenWidth) * 200.0f - 100.0f;
        float newY = ((screenHeight - y) / (float)screenHeight) * 200.0f - 100.0f;

        characterPosX = newX; // Pindahkan karakter ke posisi x kursor
        characterPosY = newY; // Pindahkan karakter ke posisi y kursor
    }

    // Tombol scroll mouse ke atas untuk mengganti warna baju secara acak
    else if (button == 3) {
        // Pilih warna secara acak
        int selectedColor = getRandomColorComponent(); 
        if (selectedColor == 0) 
            shirtColorR += 0.025f; 
        else if (selectedColor == 1) 
            shirtColorG += 0.025f; 
        else if (selectedColor == 2) 
            shirtColorB += 0.025f; 

        // Pastikan nilai warna tidak melebihi 1.0
        if (shirtColorR > 1.0f) 
            shirtColorR = 1.0f;
        if (shirtColorG > 1.0f) 
            shirtColorG = 1.0f;
        if (shirtColorB > 1.0f) 
            shirtColorB = 1.0f;
    }

    // Tombol scroll mouse ke bawah untuk mengganti warna baju secara acak
    else if (button == 4) {
        // Pilih warna secara acak
        int selectedColor = getRandomColorComponent();
        if (selectedColor == 0) 
            shirtColorR -= 0.025f; 
        else if (selectedColor == 1)
            shirtColorG -= 0.025f; 
        else if (selectedColor == 2) 
            shirtColorB -= 0.025f;

        // Pastikan nilai warna tidak kurang dari 0.0
        if (shirtColorR < 0.0f) 
            shirtColorR = 0.0f;
        if (shirtColorG < 0.0f) 
            shirtColorG = 0.0f;
        if (shirtColorB < 0.0f) 
            shirtColorB = 0.0f;
    }
}

// Fungsi untuk memperbaharui lompatan
void updateJump() {
    if (isJumping) {
        // Naikkan posisi karakter pada sumbu Y
        characterPosY += jumpSpeed; 
        jumpHeight += jumpSpeed;

        // Turunkan posisi karakter, jika sudah mencapai puncak lompatan
        if (jumpHeight >= 50.0f) {
            jumpSpeed = -jumpSpeed;
        }

        // Jika karakter sudah kembali ke posisi awal, hentikan lompatan
        if (jumpHeight <= 0.0f) {
            jumpSpeed = 0.1f; 
            jumpHeight = 0.0f;
            isJumping = false; 
        }

        glutPostRedisplay();
    }
}

// Fungsi untuk menampilkan konten pada layar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Background langit (bagian atas layar)
    glColor3f(0.6, 0.9, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-100, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 100);
        glVertex2f(-100, 100);
    glEnd();

    // Background tanah (bagian bawah layar)
    glColor3f(0.85, 0.65, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-100, -100);
    glVertex2f(100, -100);
    glVertex2f(100, 0);
    glVertex2f(-100, 0);
    glEnd();

    // Animasi awan
    glPushMatrix();
    glTranslatef(cloudPositionX, 0, 0);

    // Gambar awan
    drawCloud(-170, 70);
    drawCloud(-100, 60);
    drawCloud(-40, 40);
    drawCloud(20, 70);
    drawCloud(-80, 60);
    drawCloud(60, 50);
    drawCloud(90, 50);
    drawCloud(145, 70);

    // Animasi awan
    cloudPositionX += 0.005;
    glPopMatrix();
    if (cloudPositionX > 100) {
        cloudPositionX = -100.0f;
    }

    // Gambar karakter dengan baling-baling
    character();

    // Update lompatan jika sedang melompat
    updateJump();

    glPopMatrix();
    glutPostRedisplay();
    glFlush();
}

// Fungsi untuk inisialisasi awal
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
    // Setup glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Setup layar
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Karakter Bocah Baling");

    // Inisialisasi
    init();

    // Setup keyboard dan mouse
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse); 

    // Setup konten layar
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}