# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 07:42:42 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgtkhtml.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGTKHTML_BUILDLINK3_MK:=	${LIBGTKHTML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgtkhtml
.endif

.if !empty(LIBGTKHTML_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgtkhtml
BUILDLINK_DEPENDS.libgtkhtml+=		libgtkhtml>=2.4.1nb5
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBGTKHTML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
