# $NetBSD: buildlink3.mk,v 1.2 2007/11/05 17:06:33 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RARIAN_BUILDLINK3_MK:=	${RARIAN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	rarian
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrarian}
BUILDLINK_PACKAGES+=	rarian
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}rarian

.if ${RARIAN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.rarian+=	rarian>=0.6.0
BUILDLINK_PKGSRCDIR.rarian?=	../../textproc/rarian
.endif	# RARIAN_BUILDLINK3_MK

.if !empty(RARIAN_BUILDLINK3_MK:M+)
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
.endif	# RARIAN_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
