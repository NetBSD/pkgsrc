# $NetBSD: Makefile,v 1.8 2007/10/06 00:09:39 joerg Exp $
#

DISTNAME=	ikiwiki_2.6.1
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/i/ikiwiki/}

MAINTAINER=	reed@NetBSD.org
HOMEPAGE=	http://ikiwiki.info/
COMMENT=	Wiki compiler

PKG_OPTIONS_VAR=	PKG_OPTIONS.ikiwiki
PKG_SUPPORTED_OPTIONS=	svn w3m
PKG_SUGGESTED_OPTIONS=	# none on by default

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# http://ikiwiki.info/install/index.html
# needed dependencies:
DEPENDS+=	p5-Text-Markdown-[0-9]*:../../textproc/p5-Text-Markdown
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
# used if available:
DEPENDS+=	p5-CGI-Session-[0-9]*:../../www/p5-CGI-Session
DEPENDS+=	p5-CGI-FormBuilder>=3.05:../../www/p5-CGI-FormBuilder
DEPENDS+=	p5-Mail-Sendmail-[0-9]*:../../mail/p5-Mail-Sendmail
DEPENDS+=	p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-RPC-XML-[0-9]*:../../net/p5-RPC-XML
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-XML-Feed-[0-9]*:../../textproc/p5-XML-Feed
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

# for img plugin
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick

.if !empty(PKG_OPTIONS:Msvn)
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
.endif

.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=	w3m-[0-9]*:../../www/w3m
PLIST_SUBST+=	W3M=""
.else
PLIST_SUBST+=	W3M="@comment "
.endif


WRKSRC=		${WRKDIR}/ikiwiki
PERL5_PACKLIST=	auto/IkiWiki/.packlist
USE_LANGUAGES=	# none
USE_TOOLS=	gmake xgettext

REPLACE_PERL+=	IkiWiki.pm ikiwiki-w3m.cgi mdwn2man pm_filter
REPLACE_PERL+=	ikiwiki.in ikiwiki-mass-rebuild
REPLACE_PERL+=	t/*.t IkiWiki/*.pm IkiWiki/*/*.pm
REPLACE_PERL+=	doc/ikiwiki.setup doc/w3mmode/ikiwiki.setup

INSTALLATION_DIRS=	${PKGMANDIR}/man8

post-extract:
	cd ${WRKSRC} && ${CHMOD} a+r IkiWiki/Rcs/git.pm \
		basewiki/favicon.ico doc/logo/ikiwiki_large.png \
		doc/logo/ikiwiki.svgz templates/atomitem.tmpl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ikiwiki
	${INSTALL_DATA_DIR} ${PREFIX}/share/ikiwiki/templates
	${INSTALL_DATA_DIR} ${PREFIX}/share/ikiwiki/basewiki
	cd ${WRKSRC} && pax -rwLvpp templates basewiki ${PREFIX}/share/ikiwiki/

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ikiwiki
# This is the ikiwiki website with near 600 files and near 2MB;
# using pax -L above to copy the symlink targets for the needed doc
#	cd ${WRKSRC}/html && pax -rwvpp . ${PREFIX}/share/doc/ikiwiki/

# copy select files from docs
	${INSTALL_DATA} ${WRKSRC}/doc/ikiwiki.setup \
		${PREFIX}/share/doc/ikiwiki/ikiwiki.setup

	${INSTALL_MAN} ${WRKSRC}/ikiwiki.man ${PREFIX}/${PKGMANDIR}/man1/ikiwiki.1
	${INSTALL_MAN} ${WRKSRC}/ikiwiki-mass-rebuild.man ${PREFIX}/${PKGMANDIR}/man8/ikiwiki-mass-rebuild.8

	${INSTALL_SCRIPT} ${WRKSRC}/ikiwiki-mass-rebuild ${PREFIX}/sbin

	${INSTALL_SCRIPT} ${WRKSRC}/ikiwiki.out ${PREFIX}/bin/ikiwiki

	${GMAKE} -C ${WRKSRC}/po install PREFIX=${PREFIX}
.if !empty(PKG_OPTIONS:Mw3m)
	${INSTALL_SCRIPT} ${WRKSRC}/ikiwiki-w3m.cgi ${PREFIX}/libexec/w3m/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ikiwiki/w3mmode
	${INSTALL_DATA} ${WRKSRC}/html/w3mmode.html \
		${PREFIX}/share/doc/ikiwiki/
	${INSTALL_DATA} ${WRKSRC}/doc/w3mmode/ikiwiki.setup \
		${PREFIX}/share/doc/ikiwiki/w3mmode/ikiwiki.setup

.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
