# $NetBSD: buildlink3.mk,v 1.7 2024/08/09 09:42:37 ryoon Exp $

BUILDLINK_TREE+=	calendarsupport

.if !defined(CALENDARSUPPORT_BUILDLINK3_MK)
CALENDARSUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.calendarsupport+=	calendarsupport>=20.04.1
BUILDLINK_ABI_DEPENDS.calendarsupport?=	calendarsupport>=23.08.4nb3
BUILDLINK_PKGSRCDIR.calendarsupport?=	../../time/calendarsupport

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../time/akonadi-calendar/buildlink3.mk"
.include "../../time/kholidays/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# CALENDARSUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-calendarsupport
