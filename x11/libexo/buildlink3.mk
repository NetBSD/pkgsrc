# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/03 04:51:33 minskim Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.9.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.exo?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EXO_BUILDLINK3_MK:=	${EXO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	exo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nexo}
BUILDLINK_PACKAGES+=	exo

.if !empty(EXO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.exo+=	exo>=0.3.0
BUILDLINK_PKGSRCDIR.exo?=	../../wip-kr/libexo
.endif	# EXO_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libxfce4gui/buildlink3.mk"
#.include "../../x11/libxfce4util/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
