$NetBSD: patch-src_backend_gl_gl__common.c,v 1.2 2020/05/02 11:23:05 tnn Exp $

Parentheses are required around macro argument containing braced initializer
list.
memcpy(3) is a macro when using e.g. -D_FORTIFY_SOURCE=2.

--- src/backend/gl/gl_common.c.orig	2019-08-18 21:40:33.000000000 +0000
+++ src/backend/gl/gl_common.c
@@ -316,7 +316,7 @@ static void x_rect_to_coords(int nrects,
 		//          ri, rx, ry, rxe, rye, rdx, rdy, rdxe, rdye);
 
 		memcpy(&coord[i * 16],
-		       (GLint[][2]){
+		       ((GLint[][2]){
 		           {vx1, vy1},
 		           {texture_x1, texture_y1},
 		           {vx2, vy1},
@@ -325,11 +325,11 @@ static void x_rect_to_coords(int nrects,
 		           {texture_x2, texture_y2},
 		           {vx1, vy2},
 		           {texture_x1, texture_y2},
-		       },
+		       }),
 		       sizeof(GLint[2]) * 8);
 
 		GLuint u = (GLuint)(i * 4);
-		memcpy(&indices[i * 6], (GLuint[]){u + 0, u + 1, u + 2, u + 2, u + 3, u + 0},
+		memcpy(&indices[i * 6], ((GLuint[]){u + 0, u + 1, u + 2, u + 2, u + 3, u + 0}),
 		       sizeof(GLuint) * 6);
 	}
 }
@@ -673,8 +673,8 @@ _gl_fill(backend_t *base, struct color c
 		GLint y1 = y_inverted ? height - rect[i].y2 : rect[i].y1,
 		      y2 = y_inverted ? height - rect[i].y1 : rect[i].y2;
 		memcpy(&coord[i * 8],
-		       (GLint[][2]){
-		           {rect[i].x1, y1}, {rect[i].x2, y1}, {rect[i].x2, y2}, {rect[i].x1, y2}},
+		       ((GLint[][2]){
+		           {rect[i].x1, y1}, {rect[i].x2, y1}, {rect[i].x2, y2}, {rect[i].x1, y2}}),
 		       sizeof(GLint[2]) * 4);
 		indices[i * 6 + 0] = (GLuint)i * 4 + 0;
 		indices[i * 6 + 1] = (GLuint)i * 4 + 1;
