# $NetBSD: buildlink3.mk,v 1.5 2004/10/03 00:18:21 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SCROLLKEEPER_BUILDLINK3_MK:=	${SCROLLKEEPER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	scrollkeeper
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nscrollkeeper}
BUILDLINK_PACKAGES+=	scrollkeeper

.if !empty(SCROLLKEEPER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.scrollkeeper+=	scrollkeeper>=0.3.12nb2
BUILDLINK_RECOMMENDED.scrollkeeper+=	scrollkeeper>=0.3.14nb5
BUILDLINK_PKGSRCDIR.scrollkeeper?=	../../textproc/scrollkeeper
.endif	# SCROLLKEEPER_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"

.if !empty(SCROLLKEEPER_BUILDLINK3_MK:M+)
BUILDLINK_TARGETS+=	scrollkeeper-buildlink-fake

_SK_FAKE_UPDATE=	${BUILDLINK_DIR}/bin/scrollkeeper-update
_SK_FAKE_REBUILDDB=	${BUILDLINK_DIR}/bin/scrollkeeper-rebuilddb

scrollkeeper-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_SK_FAKE_UPDATE} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_SK_FAKE_UPDATE}";	\
		${MKDIR} ${_SK_FAKE_UPDATE:H};				\
		${ECHO} "#!/bin/sh" > ${_SK_FAKE_UPDATE};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for scrollkeeper-update' \$$*" >> ${_SK_FAKE_UPDATE};		\
		${CHMOD} +x ${_SK_FAKE_UPDATE};				\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_SK_FAKE_REBUILDDB} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_SK_FAKE_REBUILDDB}";	\
		${MKDIR} ${_SK_FAKE_REBUILDDB:H};			\
		${ECHO} "#!/bin/sh" > ${_SK_FAKE_REBUILDDB};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for scrollkeeper-rebuilddb' \$$*" >> ${_SK_FAKE_REBUILDDB};		\
		${CHMOD} +x ${_SK_FAKE_REBUILDDB};			\
	fi
.endif	# SCROLLKEEPER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
