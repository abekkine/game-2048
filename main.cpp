#include "InfraLoreFramework.h"

void render_test() {
    glLoadIdentity();
    glTranslated(400, 400, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(-200, -200);
    glVertex2i( 200, -200);
    glVertex2i( 200,  200);
    glVertex2i(-200,  200);
    glEnd();
}

int main(int argc, char *argv[]) {

    int exitCode = InfraLore::EXIT_CODE_OK;

    try {

        InfraLore::GraphicsInterface * gfx = InfraLore::getGraphics("glut");
        gfx->SetName("2048");
        gfx->SetWindowSize(800);
        gfx->AddScreenRenderer(render_test);
        gfx->Initialize();
        gfx->Run();
    }
    catch (InfraLore::Exception & e) {

        std::cerr << e.what() << '\n';
        exitCode = e.code();
    }
    catch (std::exception & e) {
        std::cerr << e.what() << '\n';
        exitCode = InfraLore::UNKNOWN_ERROR;
    }

    return exitCode;
}

