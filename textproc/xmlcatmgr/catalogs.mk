# $NetBSD: catalogs.mk,v 1.22 2019/11/04 21:43:48 rillig Exp $
#
# This Makefile fragment is intended to be included by packages that install
# catalog files or DTDs.  It takes care of registering them into the right
# database.
#
# The following variables can be defined by a package to automatically
# register catalog files:
#    SGML_CATALOGS - List of SGML catalogs to register into share/sgml/catalog.
#    XML_CATALOGS  - List of XML catalogs to register into share/xml/catalog.
#
# If you need to call xmlcatmgr with very specific arguments, you can use
# the following variables.  Add three words each time; they are fed to
# xmlcatmgr in groups of three when calling the `add' action.
#    SGML_ENTRIES - Extra arguments used to add entries to the SGML catalog.
#    XML_ENTRIES  - Extra arguments used to add entries to the XML catalog.
#

.if !defined(XMLCATMGR_CATALOGS_MK)
XMLCATMGR_CATALOGS_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# Catalogs to be registered.
SGML_CATALOGS?=
XML_CATALOGS?=

# Single entries to be added to catalogs.
SGML_ENTRIES?=
XML_ENTRIES?=

# Convert SGML_CATALOGS files into arguments for SGML_ENTRIES.
.if !empty(SGML_CATALOGS)
.  for c in ${SGML_CATALOGS}
SGML_ENTRIES+=	CATALOG ${PREFIX:=${c}} --
.  endfor
.endif

# Convert XML_CATALOGS files into arguments for XML_ENTRIES.
.if !empty(XML_CATALOGS)
.  for c in ${XML_CATALOGS}
XML_ENTRIES+=	nextCatalog ${PREFIX:=${c}} --
.  endfor
.endif

# If there are any entries to register, export required variables and
# use pkginstall framework.
#
.if !empty(SGML_ENTRIES) || !empty(XML_ENTRIES)
FILES_SUBST+=		XMLCATMGR=${XMLCATMGR:Q}
FILES_SUBST+=		SGML_CATALOG="${LOCALBASE}/share/sgml/catalog"
FILES_SUBST+=		XML_CATALOG="${LOCALBASE}/share/xml/catalog"
FILES_SUBST+=		SGML_ENTRIES=${SGML_ENTRIES:Q}
FILES_SUBST+=		XML_ENTRIES=${XML_ENTRIES:Q}
INSTALL_TEMPLATES+=	../../textproc/xmlcatmgr/files/install.tmpl
DEINSTALL_TEMPLATES+=	../../textproc/xmlcatmgr/files/deinstall.tmpl
.endif # !empty(SGML_ENTRIES) || !empty(XML_ENTRIES)

PRINT_PLIST_AWK+=	/^share\/(sgml|xml)\/catalog$$/ \
				{ print "@comment in xmlcatmgr: " $$0; next; }

# We need the xmlcatmgr tool and the catalogues, so TOOL_DEPEND and
# buildlink3.
TOOL_DEPENDS+=	xmlcatmgr-[0-9]*:../../textproc/xmlcatmgr
.include "../../textproc/xmlcatmgr/buildlink3.mk"

.endif	# XMLCATMGR_CATALOGS_MK
