# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:56:33 wiz Exp $

.if !defined(SCROLLKEEPER_BUILDLINK2_MK)
SCROLLKEEPER_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			scrollkeeper
BUILDLINK_DEPENDS.scrollkeeper?=	scrollkeeper>=0.3.12nb1
BUILDLINK_PKGSRCDIR.scrollkeeper?=	../../textproc/scrollkeeper

EVAL_PREFIX+=	BUILDLINK_PREFIX.scrollkeeper=scrollkeeper
BUILDLINK_PREFIX.scrollkeeper_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.scrollkeeper+=		lib/libscrollkeeper.*

BUILDLINK_TARGETS+=			scrollkeeper-buildlink
BUILDLINK_TARGETS+=			scrollkeeper-buildlink-fake

_SK_FAKE_UPDATE=	${BUILDLINK_DIR}/bin/scrollkeeper-update
_SK_FAKE_REBUILDDB=	${BUILDLINK_DIR}/bin/scrollkeeper-rebuilddb

scrollkeeper-buildlink: _BUILDLINK_USE

scrollkeeper-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_SK_FAKE_UPDATE} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_SK_FAKE_UPDATE}";	\
		${MKDIR} ${_SK_FAKE_UPDATE:H};			\
		${ECHO} "#!/bin/sh" > ${_SK_FAKE_UPDATE};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for scrollkeeper-update' \$$*" >> ${_SK_FAKE_UPDATE};		\
		${CHMOD} +x ${_SK_FAKE_UPDATE};			\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_SK_FAKE_REBUILDDB} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_SK_FAKE_REBUILDDB}";	\
		${MKDIR} ${_SK_FAKE_REBUILDDB:H};			\
		${ECHO} "#!/bin/sh" > ${_SK_FAKE_REBUILDDB};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for scrollkeeper-rebuilddb' \$$*" >> ${_SK_FAKE_REBUILDDB};		\
		${CHMOD} +x ${_SK_FAKE_REBUILDDB};			\
	fi

.endif	# SCROLLKEEPER_BUILDLINK2_MK
