# $NetBSD: buildlink3.mk,v 1.6 2020/03/08 16:48:27 wiz Exp $
#

BUILDLINK_TREE+=	mate-settings-daemon

.if !defined(MATE_SETTINGS_DAEMON_BUILDLINK3_MK)
MATE_SETTINGS_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-settings-daemon+=	mate-settings-daemon>=1.8.1
BUILDLINK_ABI_DEPENDS.mate-settings-daemon+=	mate-settings-daemon>=1.22.1nb1
BUILDLINK_PKGSRCDIR.mate-settings-daemon?=	../../x11/mate-settings-daemon

.include "../../x11/libmatekbd/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.endif	# MATE_SETTINGS_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-settings-daemon
