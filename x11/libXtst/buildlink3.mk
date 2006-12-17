# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/12/17 18:03:55 joerg Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libXtst?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXTST_BUILDLINK3_MK:=	${LIBXTST_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXtst
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXtst}
BUILDLINK_PACKAGES+=	libXtst
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXtst

.if ${LIBXTST_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXtst+=	libXtst>=1.0.1
BUILDLINK_PKGSRCDIR.libXtst?=	../../x11/libXtst
.endif	# LIBXTST_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/renderproto/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
#.include "../../x11/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
