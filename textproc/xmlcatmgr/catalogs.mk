# $NetBSD: catalogs.mk,v 1.3 2004/02/01 10:11:39 jlam Exp $
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

# Catalogs to be registered.
SGML_CATALOGS?=
XML_CATALOGS?=

# Single entries to be added to catalogs.
SGML_ENTRIES?=
XML_ENTRIES?=

# Convert SGML_CATALOGS files into arguments for SGML_ENTRIES.
.if !empty(SGML_CATALOGS)
.for c in ${SGML_CATALOGS}
SGML_ENTRIES+=	CATALOG ${PREFIX:=$c} --
.endfor
.endif

# Convert XML_CATALOGS files into arguments for XML_ENTRIES.
.if !empty(XML_CATALOGS)
.for c in ${XML_CATALOGS}
XML_ENTRIES+=	nextCatalog ${PREFIX:=$c} --
.endfor
.endif

# If there are any entries to register, export required variables and
# use bsd.pkg.install.mk.
.if !empty(SGML_ENTRIES) || !empty(XML_ENTRIES)
FILES_SUBST+=	XMLCATMGR="${XMLCATMGR}"
FILES_SUBST+=	SGML_CATALOG="${BUILDLINK_PREFIX.xmlcatmgr}/share/sgml/catalog"
FILES_SUBST+=	XML_CATALOG="${BUILDLINK_PREFIX.xmlcatmgr}/share/xml/catalog"
FILES_SUBST+=	SGML_ENTRIES="${SGML_ENTRIES}"
FILES_SUBST+=	XML_ENTRIES="${XML_ENTRIES}"
INSTALL_EXTRA_TMPL+=	../../textproc/xmlcatmgr/files/install.tmpl
DEINSTALL_EXTRA_TMPL+=	../../textproc/xmlcatmgr/files/deinstall.tmpl
USE_PKGINSTALL=	YES
.endif # !empty(SGML_ENTRIES) || !empty(XML_ENTRIES)

.if !empty(USE_BUILDLINK3:[yY][eE][sS])
.  include "../../textproc/xmlcatmgr/buildlink3.mk"
.elif empty(USE_BUILDLINK2:[nN][oO])
.  include "../../textproc/xmlcatmgr/buildlink2.mk"
.endif

.endif	# XMLCATMGR_CATALOGS_MK
