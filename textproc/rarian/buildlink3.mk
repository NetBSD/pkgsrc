# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	rarian

.if !defined(RARIAN_BUILDLINK3_MK)
RARIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rarian+=	rarian>=0.6.0
BUILDLINK_PKGSRCDIR.rarian?=	../../textproc/rarian

BUILDLINK_TARGETS+=	rarian-buildlink-fake

rarian-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for fake in scrollkeeper-update	scrollkeeper-rebuilddb		\
	    rarian-sk-update rarian-sk-rebuild;				\
	do								\
		if [ ! -f ${BUILDLINK_DIR}/bin/$${fake} ]; then		\
			${ECHO_BUILDLINK_MSG}				\
			    "Creating ${BUILDLINK_DIR}/bin/$${fake}";	\
			${MKDIR} ${BUILDLINK_DIR}/bin;			\
			${ECHO} "#!/bin/sh"				\
			    > ${BUILDLINK_DIR}/bin/$${fake};		\
			${ECHO} "echo '[pkgsrc] Doing nothing for"	\
			    "$${fake}' \$$*"				\
			    >>${BUILDLINK_DIR}/bin/$${fake};		\
			${CHMOD} +x ${BUILDLINK_DIR}/bin/$${fake};	\
		fi;							\
	done
.endif # RARIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-rarian
