# $NetBSD: buildlink3.mk,v 1.2 2015/04/25 14:25:03 tnn Exp $

BUILDLINK_TREE+=	c++-gtk-utils

.if !defined(C++_GTK_UTILS_BUILDLINK3_MK)
C++_GTK_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c++-gtk-utils+=	c++-gtk-utils>=2.2.7
BUILDLINK_ABI_DEPENDS.c++-gtk-utils?=	c++-gtk-utils>=2.2.11nb1
BUILDLINK_PKGSRCDIR.c++-gtk-utils?=	../../x11/c++-gtk-utils

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# C++_GTK_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-c++-gtk-utils
