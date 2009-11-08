# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/11/08 18:26:15 jakllsch Exp $

BUILDLINK_TREE+=	libxdg-basedir

.if !defined(LIBXDG_BASEDIR_BUILDLINK3_MK)
LIBXDG_BASEDIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxdg-basedir+=	libxdg-basedir>=1.0.2
BUILDLINK_PKGSRCDIR.libxdg-basedir?=	../../x11/libxdg-basedir
.endif	# LIBXDG_BASEDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxdg-basedir
