# $NetBSD: buildlink3.mk,v 1.11 2009/06/14 22:58:09 joerg Exp $
#
# This Makefile fragment is included by packages that use xmlcatmgr.
#
# The following variables are automatically defined for free use in packages:
#    XMLCATMGR            - Path to the xmlcatmgr program.
#    SGML_DEFAULT_CATALOG - Path to the system-wide (tunable) SGML catalog.
#    XML_DEFAULT_CATALOG  - Path to the system-wide (tunable) XML catalog.
#
# Packages that recognize a system-wide catalog file should be configured
# to use SGML_DEFAULT_CATALOG or XML_DEFAULT_CATALOG, depending on the
# type of tool they are.
#

BUILDLINK_TREE+=	xmlcatmgr

.if !defined(XMLCATMGR_BUILDLINK3_MK)
XMLCATMGR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmlcatmgr+=		xmlcatmgr>=2.0beta1
BUILDLINK_PKGSRCDIR.xmlcatmgr?=		../../textproc/xmlcatmgr

# Location of the xmlcatmgr binary program.
EVAL_PREFIX+=			XMLCATMGR_PREFIX=xmlcatmgr
XMLCATMGR_PREFIX_DEFAULT=	${LOCALBASE}
XMLCATMGR=			${XMLCATMGR_PREFIX}/bin/xmlcatmgr

# System-wide configurable catalogs.
.if defined(PKG_SYSCONFDIR.xmlcatmgr) && !empty(PKG_SYSCONFDIR.xmlcatmgr)
SGML_DEFAULT_CATALOG=	${PKG_SYSCONFDIR.xmlcatmgr}/sgml/catalog
XML_DEFAULT_CATALOG=	${PKG_SYSCONFDIR.xmlcatmgr}/xml/catalog
.else
SGML_DEFAULT_CATALOG=	${PKG_SYSCONFBASEDIR}/sgml/catalog
XML_DEFAULT_CATALOG=	${PKG_SYSCONFBASEDIR}/xml/catalog
.endif

.endif # XMLCATMGR_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmlcatmgr
