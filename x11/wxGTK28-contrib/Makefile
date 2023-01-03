# $NetBSD: Makefile,v 1.48 2023/01/03 17:36:39 wiz Exp $

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK28-contrib/}
PKGREVISION=	19
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		build-non-unicode/contrib/src \
			build-unicode/contrib/src

# We patch configure
CHECK_PORTABILITY_SKIP+=	configure.in

INSTALL_TARGET=		install

BUILDLINK_DEPMETHOD.libXt?=	build

# ../../../../contrib/src/stc/scintilla/src/Editor.cxx: In member function 'void Editor::LayoutLine(int, Surface*, ViewStyle&, LineLayout*, int)':
# ../../../../contrib/src/stc/scintilla/src/Editor.cxx:2048:47: error: array subscript has type 'char' [-Werror=char-subscripts]
#         if (ctrlCharWidth[ll->chars[charInLine]] == 0) {
#                                                ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
