$NetBSD: patch-src_backend_gl_gl__common.c,v 1.1 2019/12/15 14:05:47 nia Exp $

error: macro "memcpy" passed 19 arguments, but takes just 3

--- src/backend/gl/gl_common.c.orig	2019-11-18 21:59:30.000000000 +0000
+++ src/backend/gl/gl_common.c
@@ -315,22 +315,23 @@ static void x_rect_to_coords(int nrects,
 		// log_trace("Rect %d: %f, %f, %f, %f -> %d, %d, %d, %d",
 		//          ri, rx, ry, rxe, rye, rdx, rdy, rdxe, rdye);
 
-		memcpy(&coord[i * 16],
-		       (GLint[][2]){
-		           {vx1, vy1},
-		           {texture_x1, texture_y1},
-		           {vx2, vy1},
-		           {texture_x2, texture_y1},
-		           {vx2, vy2},
-		           {texture_x2, texture_y2},
-		           {vx1, vy2},
-		           {texture_x1, texture_y2},
-		       },
-		       sizeof(GLint[2]) * 8);
+		GLint temp1[8][2] = {
+		   {vx1, vy1},
+		   {texture_x1, texture_y1},
+		   {vx2, vy1},
+		   {texture_x2, texture_y1},
+		   {vx2, vy2},
+		   {texture_x2, texture_y2},
+		   {vx1, vy2},
+		   {texture_x1, texture_y2},
+		};
+
+		memcpy(&coord[i * 16], temp1, sizeof(GLint[2]) * 8);
 
 		GLuint u = (GLuint)(i * 4);
-		memcpy(&indices[i * 6], (GLuint[]){u + 0, u + 1, u + 2, u + 2, u + 3, u + 0},
-		       sizeof(GLuint) * 6);
+		GLuint temp2[] = {u + 0, u + 1, u + 2, u + 2, u + 3, u + 0};
+
+		memcpy(&indices[i * 6], temp2, sizeof(GLuint) * 6);
 	}
 }
 
@@ -672,10 +673,9 @@ _gl_fill(backend_t *base, struct color c
 	for (int i = 0; i < nrects; i++) {
 		GLint y1 = y_inverted ? height - rect[i].y2 : rect[i].y1,
 		      y2 = y_inverted ? height - rect[i].y1 : rect[i].y2;
-		memcpy(&coord[i * 8],
-		       (GLint[][2]){
-		           {rect[i].x1, y1}, {rect[i].x2, y1}, {rect[i].x2, y2}, {rect[i].x1, y2}},
-		       sizeof(GLint[2]) * 4);
+		GLint temp1[4][2] = {
+		{rect[i].x1, y1}, {rect[i].x2, y1}, {rect[i].x2, y2}, {rect[i].x1, y2}};
+		memcpy(&coord[i * 8], temp1, sizeof(GLint[2]) * 4);
 		indices[i * 6 + 0] = (GLuint)i * 4 + 0;
 		indices[i * 6 + 1] = (GLuint)i * 4 + 1;
 		indices[i * 6 + 2] = (GLuint)i * 4 + 2;
