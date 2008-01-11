# $NetBSD: zopeversion.mk,v 1.4 2008/01/11 15:41:02 taca Exp $
#

.if !defined(_ZOPEVERSION_MK)
_ZOPEVERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# The following variables may be set by the pkgsrc user in mk.conf:
#
# ZOPE_VERSION_DEFAULT
#	The preferred Zope version to use.
#	Possible value: (all)
#
# ZOPE_VERSION_ACCEPTED
#	The Zope version that are acceptable for the package.
#	The order of the entries matters.
#
# ZOPE_VERSION_REQD
#	The specific Zope version that are acceptable for the package.
#
# ZOPE_USER
#	Default Zope running user.
#
# ZOPE_GROUP
#	Default Zope running group.
#

# The following variables may not be set by the pkgsrc user in mk.conf:
#
# ZOPE_VERSION_SUPPORTED
#	Known Zope release which we support.
#
# ZOPE_PKG
#	Short name for each Zope major release; zope29, zope210 and
#	hopefully zope3.
#
# ZOPE_USE_PYPKGPREFIX
#	Bool variable which enable prefix Zope based package with
#	${ZOPE_PKG}.  (Experimental)
#
# ZOPE_COMMON
#	Basename of directory to install Zope.
#
# ZOPE_PRODUCTS_BASE
#	Basename of directory for Zope extention packages.
#	
# ZOPE_DOC_BASE
#	Documentation directory for Zope packages.
#
#

ZOPE_VERSION_SUPPORTED=	29 210 # 211 33

ZOPE_VERSION_DEFAULT?=	29
ZOPE_VERSION_ACCEPTED?=	${ZOPE_VERSION_SUPPORTED}

# current Zope version
ZOPE29_VERSION=		2.9.8
ZOPE210_VERSION=	2.10.5
ZOPE211_VERSION=	2.11.0
ZOPE33_VERSION=		3.3.1

ZOPE_USER?=		zope
ZOPE_GROUP?=		zope

ZOPE_USE_PYPKGPREFIX?=	no

.if !empty(ZOPE_USE_PYPKGPREFIX:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.zope29?=		${PYPKGPREFIX}-zope29>=2.9.7
BUILDLINK_API_DEPENDS.zope210?=		${PYPKGPREFIX}-zope210>=2.10.3
BUILDLINK_API_DEPENDS.zope211?=		${PYPKGPREFIX}-zope211>=2.11.0
BUILDLINK_API_DEPENDS.zope33?=		${PYPKGPREFIX}-zope33>=3.3.1
.else
BUILDLINK_API_DEPENDS.zope29?=		zope29>=2.9.7
BUILDLINK_API_DEPENDS.zope210?=		zope210>=2.10.3
BUILDLINK_API_DEPENDS.zope211?=		zope210>=2.11.0
BUILDLINK_API_DEPENDS.zope33?=		zope33>=3.3.1
.endif

ZOPE_COMMON?=		zope
ZOPE_BASE=		${ZOPE_COMMON}/${ZOPE_PKG}
ZOPE_DOC_BASE?=		share/doc/${ZOPE_PKG}
ZOPE_PRODUCTS_BASE=	${ZOPE_BASE}/Products

ZOPE_DIR=		${PREFIX}/${ZOPE_BASE}
ZOPE_DOC_DIR=		${PREFIX}/${ZOPE_DOC_BASE}
ZOPE_PRODUCTS_DIR=	${PREFIX}/${ZOPE_PRODUCTS_BASE}

# transform the list into individual variables
.for zv in ${ZOPE_VERSION_ACCEPTED}
_ZOPE_VERSION_${zv}_OK=	yes
.endfor

# check what is installed
.for zv in ${ZOPE_VERSION_SUPPORTED}
.if exists(${LOCALBASE}/${ZOPE_COMMON}/zope${zv})
_ZOPE_VERSION_${zv}_INSTALLED=	yes
.endif
.endfor

# if a version is explicitly required, take it
.if defined(ZOPE_VERSION_REQD)
_ZOPE_VERSION=	${ZOPE_VERSION_REQD}
.endif

#if a default is already installed, it is first choice
.if !defined(_ZOPE_VERSION)
.if defined(_ZOPE_VERSION_${ZOPE_VERSION_DEFAULT}_OK)
.if defined(_ZOPE_VERSION_${ZOPE_VERSION_DEFAULT}_INSTALLED)
_ZOPE_VERSION=	${ZOPE_VERSION_DEFAULT}
.endif
.endif
.endif
# prefer an already installed version, in order of "accepted"
.if !defined(_ZOPE_VERSION)
.for zv in ${ZOPE_VERSION_ACCEPTED}
.if defined(_ZOPE_VERSION_${zv}_INSTALLED)
_ZOPE_VERSION?=	${zv}
.else
# keep information as last resort - see below
_ZOPE_VERSION_FIRSTACCEPTED?=	${zv}
.endif
.endfor
.endif
# if the default is OK for the addon pkg, take this
.if !defined(_ZOPE_VERSION)
.if defined(_ZOPE_VERSION_${ZOPE_VERSION_DEFAULT}_OK)
_ZOPE_VERSION=   ${ZOPE_VERSION_DEFAULT}
.endif
.endif
# take the first one accepted by the package
.if !defined(_ZOPE_VERSION)
_ZOPE_VERSION=   ${_ZOPE_VERSION_FIRSTACCEPTED}
.endif

#
ZOPE_VERSION?=	${_ZOPE_VERSION}
ZOPE_PKG:=	zope${ZOPE_VERSION}

# force the selected ZOPE version for recursive builds
ZOPE_VERSION_REQD:=	${ZOPE_VERSION}

ZOPE_PKGSRC_DIR=	../../www/${ZOPE_PKG}
.if !empty(ZOPE_USE_PYPKGPREFIX:M[Yy][Ee][Ss])
ZOPE_PKG_PREFIX=	${PYPKGPREFIX}-${ZOPE_PKG}
.else
ZOPE_PKG_PREFIX=	${ZOPE_PKG}
.endif

.if ${_ZOPE_VERSION} == "29"
ZOPE_DEPENDENCY=	${BUILDLINK_API_DEPENDS.zope29}:${ZOPE_PKGSRC_DIR}
EVAL_PREFIX+=		BUILDLINK_PREFIX.zope29=${ZOPE_PKG}
BUILDLINK_PREFIX.zope29_DEFAULT= ${LOCALBASE}
.elif ${_ZOPE_VERSION} == "210"
ZOPE_DEPENDENCY=	${BUILDLINK_API_DEPENDS.zope210}:${ZOPE_PKGSRC_DIR}
EVAL_PREFIX+=		BUILDLINK_PREFIX.zope210=${ZOPE_PKG}
BUILDLINK_PREFIX.zope211_DEFAULT= ${LOCALBASE}
.elif ${_ZOPE_VERSION} == "211"
ZOPE_DEPENDENCY=	${BUILDLINK_API_DEPENDS.zope211}:${ZOPE_PKGSRC_DIR}
EVAL_PREFIX+=		BUILDLINK_PREFIX.zope211=${ZOPE_PKG}
BUILDLINK_PREFIX.zope211_DEFAULT= ${LOCALBASE}
.elif ${_ZOPE_VERSION} == "33"
ZOPE_DEPENDENCY=	${BUILDLINK_API_DEPENDS.zope33}:${ZOPE_PKGSRC_DIR}
EVAL_PREFIX+=		BUILDLINK_PREFIX.zope33=${ZOPE_PKG}
BUILDLINK_PREFIX.zope33_DEFAULT= ${LOCALBASE}
.else
PKG_SKIP_REASON+=	"No valid Zope version"
.endif

BUILD_DEFS+=		ZOPE_VERSION
BUILD_DEFS_EFFECTS+=	ZOPE_PKG

FILES_SUBST+=	ZOPE_PKG=${ZOPE_PKG} ZOPE_VERSION=${ZOPE_VERSION}

MESSAGE_SUBST+=	ZOPE_VERSION=${ZOPE_VERSION} \
		ZOPE_COMMON=${ZOPE_COMMON} \
		ZOPE_PKG=${ZOPE_PKG} \
		ZOPE_DIR=${ZOPE_DIR} \
		ZOPE_PRODUCTS_DIR=${ZOPE_PRODUCTS_DIR} \
		ZOPE_GROUP=${ZOPE_GROUP:Q} \
		ZOPE_USER=${ZOPE_USER:Q}

PLIST_SUBST+=	ZOPE_VERSION=${ZOPE_VERSION} \
		ZOPE_BASE=${ZOPE_BASE} \
		ZOPE_COMMON=${ZOPE_COMMON} \
		ZOPE_DOC_BASE=${ZOPE_DOC_BASE} \
		ZOPE_PRODUCTS_BASE=${ZOPE_PRODUCTS_BASE}

#
ZOPE_PY_COMPILE= ${PYTHONBIN} ${ZOPE_DIR}/bin/compilezpy.py
PY_COMPILE_ALL= \
	${PYTHONBIN} ${PREFIX}/lib/python${PYVERSSUFFIX}/compileall.py -q

.endif
