#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

int main()
{
	InitWindow(768, 768, "Math");

	Camera camera;
	camera.position = { 4.0f, 6.0f, 8.0f };
	camera.target = Vector3Zeros;
	camera.up = Vector3UnitY;
	camera.fovy = 90.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Mesh mesh = GenMeshCube(1.0f, 1.0f, 1.0f);
	Material material = LoadMaterialDefault();

	int scene = 0;
	DisableCursor();
	while (!WindowShouldClose())
	{
		UpdateCamera(&camera, CAMERA_FREE);

		if (IsKeyPressed(KEY_TWO))
			++scene %= 10;
		if (IsKeyPressed(KEY_ONE))
		{
			scene += 10;
			--scene %= 10;
		}

		Color color = BLANK;
		Matrix matrix = MatrixIdentity();

		if (scene == 0)
		{
			color = RED;
			matrix = MatrixTranslate(3.0f, 0.0f, 0.0f);
		}
		if (scene == 1)
		{
			color = GREEN;
			matrix = MatrixTranslate(0.0f, 3.0f, 0.0f);
		}
		if (scene == 2)
		{
			color = BLUE;
			matrix = MatrixTranslate(0.0f, 0.0f, 3.0f);
		}
		if (scene == 3)
		{
			color = RED;
			matrix = MatrixRotateX(100.0f * DEG2RAD * GetTime());
		}
		if (scene == 4)
		{
			color = GREEN;
			matrix = MatrixRotateY(100.0f * DEG2RAD * GetTime());
		}
		if (scene == 5)
		{
			color = BLUE;
			matrix = MatrixRotateZ(100.0f * DEG2RAD * GetTime());
		}
		if (scene == 6)
		{
			color = VIOLET;
			matrix = MatrixRotateY(100.0f * DEG2RAD * GetTime()) * MatrixTranslate(0.0f, 0.0f, 3.0f);
		}
		if (scene == 7)
		{
			color = PURPLE;
			matrix = MatrixTranslate(0.0f, 0.0f, 3.0f) * MatrixRotateY(100.0f * DEG2RAD * GetTime());
		}
		if (scene == 8)
		{
			float s = (sinf(GetTime()) * 0.5f + 0.5f) * 5.0f;
			color = BEIGE;
			matrix = MatrixScale(s, s, s) * MatrixRotateY(100.0f * DEG2RAD * GetTime()) * MatrixTranslate(0.0f, 0.0f, 3.0f);
		}
		if (scene == 9)
		{
			float s = (sinf(GetTime()) * 0.5f + 0.5f) * 5.0f;
			color = LIGHTGRAY;
			matrix = MatrixTranslate(0.0f, 0.0f, 3.0f) * MatrixRotateY(100.0f * DEG2RAD * GetTime()) * MatrixScale(s, s, s);
		}

		BeginDrawing();
		BeginMode3D(camera);
		ClearBackground(WHITE);
		DrawGrid(10, 10);
		DrawLine3D(Vector3Zeros, Vector3UnitX * 10.0f, RED);
		DrawLine3D(Vector3Zeros, Vector3UnitY * 10.0f, GREEN);
		DrawLine3D(Vector3Zeros, Vector3UnitZ * 10.0f, BLUE);
		material.maps[MATERIAL_MAP_DIFFUSE].color = color;
		DrawMesh(mesh, material, matrix);

		EndMode3D();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
