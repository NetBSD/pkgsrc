# $NetBSD: buildlink.mk,v 1.1 2001/05/26 07:14:01 jlam Exp $
#
# This Makefile fragment is included by packages that use FLTK.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define FLTK_REQD to the version of FLTK desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(FLTK_BUILDLINK_MK)
FLTK_BUILDLINK_MK=	# defined

FLTK_REQD?=		1.0.9

.include "../../graphics/Mesa/buildlink.mk"

# We double-list because we're not sure if the files are in ${X11BASE}
# or in ${LOCALBASE}.

FLTK_HEADERS=		${X11BASE}/include/FL/*
FLTK_HEADERS+=		${LOCALBASE}/include/FL/*
FLTK_LIBS=		${X11BASE}/lib/libfltk.*
FLTK_LIBS+=		${LOCALBASE}/lib/libfltk.*
DEPENDS+=		fltk>=${FLTK_REQD}:../../x11/fltk

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-fltk-headers
BUILDLINK_TARGETS+=	link-fltk-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-fltk-headers:
	@${ECHO} "Linking fltk headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/FL
	@${RM} -f ${BUILDLINK_INCDIR}/FL/*
	@for inc in ${FLTK_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/FL/`${BASENAME} $${inc}`;	\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-fltk-libs:
	@${ECHO} "Linking fltk libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${FLTK_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# FLTK_BUILDLINK_MK
