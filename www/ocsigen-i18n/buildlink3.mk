# $NetBSD: buildlink3.mk,v 1.5 2020/12/11 10:58:20 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-i18n

.if !defined(OCSIGEN_I18N_BUILDLINK3_MK)
OCSIGEN_I18N_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-i18n+=	ocsigen-i18n>=3.7.0
BUILDLINK_ABI_DEPENDS.ocsigen-i18n+=	ocsigen-i18n>=3.7.0
BUILDLINK_PKGSRCDIR.ocsigen-i18n?=	../../www/ocsigen-i18n
.endif	# OCSIGEN_I18N_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-i18n
