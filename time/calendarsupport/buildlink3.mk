# $NetBSD: buildlink3.mk,v 1.21 2026/07/13 04:36:32 wiz Exp $

BUILDLINK_TREE+=	calendarsupport

.if !defined(CALENDARSUPPORT_BUILDLINK3_MK)
CALENDARSUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.calendarsupport+=	calendarsupport>=25.08.3
BUILDLINK_ABI_DEPENDS.calendarsupport?=	calendarsupport>=25.08.3nb6
BUILDLINK_PKGSRCDIR.calendarsupport?=	../../time/calendarsupport

.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# CALENDARSUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-calendarsupport
