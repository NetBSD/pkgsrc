# $NetBSD: ploneversion.mk,v 1.3 2008/02/19 14:12:46 taca Exp $
#

.if !defined(_PLONEVERSION_MK)
_PLONEVERSION_MK=	# defined

.include "../../www/zope/zopeversion.mk"

# The following variables may be set by the pkgsrc user in mk.conf:
#
# PLONE_VERSION_DEFAULT
#	The preferred Plone version to use.
#	Possible value: (all)
#
# PLONE_VERSION_ACCEPTED
#	The Plone version that are acceptable for the package.
#	The order of the entries matters.
#
# PLONE_VERSION_REQD
#	The specific Plone version that are acceptable for the package.
#

# The following variables may not be set by the pkgsrc user in mk.conf:
#
# PLONE_VERSION_SUPPORTED
#	Known Plone release which we support.
#
# PLONE_PKG
#	
# PLONE_PKG_PREFIX_ZOPE=
#	always, yes, no

.if ${ZOPE_VERSION} == "29"
PLONE_VERSION_SUPPORTED=	25
.elif ${ZOPE_VERSION} == "210"
PLONE_VERSION_SUPPORTED=	3
.endif

PLONE_VERSION_DEFAULT?=		25
PLONE_VERSION_ACCEPTED?=	${PLONE_VERSION_SUPPORTED}

# current Plone version
PLONE25_VERSION=		2.5.5
PLONE3_VERSION=			3.0.6

BUILDLINK_API_DEPENDS.plone25?=	plone25>=${PLONE25_VERSION}
BUILDLINK_API_DEPENDS.plone3?=	plone30>=${PLONE3_VERSION}

PLONE_PKG_PREFIX_ZOPE?=		no

PLONE_BASE=			${ZOPE_BASE}/${PLONE_PKG}
PLONE_DOC_BASE?=		share/doc/${PLONE_PKG}

PLONE_DIR=			${PREFIX}/${PLONE_BASE}
PLONE_DOC_DIR=			${PREFIX}/${PLONE_DOC_BASE}

ZOPE_PRODUCT_DST?=	# empty
ZOPE_PRODUCT_DSTDIR?=	${PLONE_DIR}

# transform the list into individual variables
.for pv in ${PLONE_VERSION_ACCEPTED}
_PLONE_VERSION_${pv}_OK=	yes
.endfor

# check what is installed
.for pv in ${PLONE_VERSION_SUPPORTED}
.if exists(${LOCALBASE}/${ZOPE_COMMON}/${ZOPE_PKG}/plone${pv})
_PLONE_VERSION_${pv}_INSTALLED=	yes
.endif
.endfor

# if a version is explicitly required, take it
.if defined(PLONE_VERSION_REQD)
_PLONE_VERSION=	${PLONE_VERSION_REQD}
.endif

#if a default is already installed, it is first choice
.if !defined(_PLONE_VERSION)
.if defined(_PLONE_VERSION_${PLONE_VERSION_DEFAULT}_OK)
.if defined(_PLONE_VERSION_${PLONE_VERSION_DEFAULT}_INSTALLED)
_PLONE_VERSION=	${PLONE_VERSION_DEFAULT}
.endif
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_PLONE_VERSION)
.for pv in ${PLONE_VERSION_ACCEPTED}
.if defined(_PLONE_VERSION_${pv}_INSTALLED)
_PLONE_VERSION?=	${pv}
.else
# keep information as last resort - see below
_PLONE_VERSION_FIRSTACCEPTED?=	${pv}
.endif
.endfor
.endif
# if the default is OK for the addon pkg, take this
.if !defined(_PLONE_VERSION)
.if defined(_PLONE_VERSION_${PLONE_VERSION_DEFAULT}_OK)
_PLONE_VERSION=   ${PLONE_VERSION_DEFAULT}
.endif
.endif
# take the first one accepted by the package
.if !defined(_PLONE_VERSION)
_PLONE_VERSION=   ${_PLONE_VERSION_FIRSTACCEPTED}
.endif

#
PLONE_VERSION?=	${_PLONE_VERSION}
PLONE_PKG:=	plone${PLONE_VERSION}

# force the selected PLONE version for recursive builds
PLONE_VERSION_REQD:=	${PLONE_VERSION}

PLONE_PKGSRC_DIR=	../../www/${PLONE_PKG}

#
.if !empty(PLONE_PKG_PREFIX_ZOPE:Malways) || \
	(${ZOPE_VERSION_ACCEPTED:[\#]} > 1 && \
	empty(PLONE_PKG_PREFIX_ZOPE:M[Nn][Oo]))
PLONE_PKG_PREFIX=	${ZOPE_PKG_PREFIX}-${PLONE_PKG}
.else
PLONE_PKG_PREFIX=	${PLONE_PKG}
.endif

PLONE_DEPENDENCY=	${BUILDLINK_API_DEPENDS}${PLONE_PKG_PREFIX}>=${PLONE25_VERSION}:${PLONE_PKGSRC_DIR}	
EVAL_PREFIX+=		BUILDLINK_PREFIX.${PLONE_PKG_PREFIX}=${PLONE_PKG}
.if ${_PLONE_VERSION} == "25"
BUILDLINK_PREFIX.plone25_DEFAULT= ${LOCALBASE}
.elif ${_PLONE_VERSION} == "3"
BUILDLINK_PREFIX.plone3_DEFAULT= ${LOCALBASE}
.else
PKG_SKIP_REASON+=	"No valid Plone version"
.endif

BUILD_DEFS+=		PLONE_VERSION
BUILD_DEFS_EFFECTS+=	PLONE_PKG

MESSAGE_SUBST+=	PLONE_VERSION=${PLONE_VERSION} \
		PLONE_PKG=${PLONE_PKG} \
		PLONE_DIR=${PLONE_DIR} \
		PLONE_GROUP=${PLONE_GROUP:Q} \
		PLONE_USER=${PLONE_USER:Q}
PLIST_SUBST+=	PLONE_VERSION=${PLONE_VERSION} \
		PLONE_BASE=${PLONE_BASE} \
		PLONE_DOC_BASE=${PLONE_DOC_BASE}

.include "../../www/zope/product.mk"

.endif
