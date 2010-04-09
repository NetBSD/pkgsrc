# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/09 23:36:21 markd Exp $

BUILDLINK_TREE+=	shared-desktop-ontologies

.if !defined(SHARED_DESKTOP_ONTOLOGIES_BUILDLINK3_MK)
SHARED_DESKTOP_ONTOLOGIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shared-desktop-ontologies+=	shared-desktop-ontologies>=0.3
BUILDLINK_PKGSRCDIR.shared-desktop-ontologies?=	../../textproc/shared-desktop-ontologies
.endif	# SHARED_DESKTOP_ONTOLOGIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-shared-desktop-ontologies
