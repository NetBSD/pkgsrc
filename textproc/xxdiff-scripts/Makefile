# $NetBSD: Makefile,v 1.2 2018/03/11 21:23:28 ginsbach Exp $

.include "../../textproc/xxdiff/Makefile.common"

PKGNAME=	xxdiff-scripts-${XXDIFFVERSION}
COMMENT=	Helper scripts for xxdiff

DEPENDS+=	xxdiff-${XXDIFFVERSION}:../../textproc/xxdiff

USE_TOOLS=	# empty

#PYTHON_VERSIONS_INCOMPATIBLE=	# XXX unknown
REPLACE_PYTHON+=	bin/svn-foreign
REPLACE_PYTHON+=	bin/xx-cond-replace bin/xx-cvs-diff bin/xx-cvs-revcmp
REPLACE_PYTHON+=	bin/xx-diff-proxy bin/xx-encrypted bin/xx-filter
REPLACE_PYTHON+=	bin/xx-find-grep-sed bin/xx-hg-merge bin/xx-match
REPLACE_PYTHON+=	bin/xx-p4-unmerge bin/xx-pyline bin/xx-rename
REPLACE_PYTHON+=	bin/xx-sql-schemas bin/xx-svn-diff bin/xx-svn-resolve
REPLACE_PYTHON+=	bin/xx-svn-review

INSTALLATION_DIRS+=	${XXDIFFDOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xxdiff-scripts.html ${DESTDIR}${PREFIX}/${XXDIFFDOCDIR}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
