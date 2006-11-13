# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 01:25:25 dan Exp $
#

DISTNAME=	ikiwiki_1.32
PKGNAME=	ikiwiki-1.32
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/i/ikiwiki/}

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://ikiwiki.kitenet.net/
COMMENT=	Wiki compiler


PKG_OPTIONS_VAR=	PKG_OPTIONS.ikiwiki
PKG_SUPPORTED_OPTIONS=	svn w3m
PKG_SUGGESTED_OPTIONS=	svn w3m

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

DEPENDS+=	Markdown>=1.0.1:../../textproc/Markdown
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-CGI-Session-[0-9]*:../../www/p5-CGI-Session
DEPENDS+=	p5-CGI-FormBuilder>=3.0202:../../www/p5-CGI-FormBuilder
DEPENDS+=	p5-Mail-Sendmail-[0-9]*:../../mail/p5-Mail-Sendmail
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

.if !empty(PKG_OPTIONS:Msvn)
DEPENDS+=	subversion-[0-9]*:../../devel/subversion
.endif

.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=	w3m-[0-9]*:../../www/w3m
.endif


# optional modules I couldn't find
#DEPENDS+=	Time::Duration
#DEPENDS+=	RPC::XML
#DEPENDS+=	XML::Feed

WRKSRC=		${WRKDIR}/ikiwiki
PERL5_PACKLIST=	auto/IkiWiki/.packlist
USE_LANGUAGES=	# none
USE_TOOLS=	gmake

REPLACE_PERL+=	ikiwiki.pl IkiWiki.pm ikiwiki-w3m.cgi mdwn2man pm_filter
REPLACE_PERL+=	t/*.t IkiWiki/*.pm IkiWiki/*/*.pm
REPLACE_PERL+=	doc/ikiwiki.setup doc/w3mmode/ikiwiki.setup


post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ikiwiki
	${INSTALL_DATA_DIR} ${PREFIX}/share/ikiwiki/templates
	${INSTALL_DATA_DIR} ${PREFIX}/share/ikiwiki/basewiki
	cd ${WRKSRC} && pax -rwvpp templates basewiki ${PREFIX}/share/ikiwiki/

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ikiwiki
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ikiwiki/html
	cd ${WRKSRC}/doc  && pax -rwvpp . ${PREFIX}/share/doc/ikiwiki/
	cd ${WRKSRC}/html && pax -rwvpp . ${PREFIX}/share/doc/ikiwiki/html

	${INSTALL_MAN} ${WRKSRC}/ikiwiki.man ${PREFIX}/${PKGMANDIR}/man1/ikiwiki.1
	${INSTALL_MAN} ${WRKSRC}/ikiwiki-mass-rebuild.man ${PREFIX}/${PKGMANDIR}/man8/ikiwiki-mass-rebuild.8

	${INSTALL_SCRIPT} ${WRKSRC}/ikiwiki-mass-rebuild ${PREFIX}/sbin

	${INSTALL_SCRIPT} ${WRKSRC}/ikiwiki-w3m.cgi ${PREFIX}/libexec/w3m/cgi-bin

	${INSTALL_SCRIPT} ${WRKSRC}/ikiwiki.out ${PREFIX}/bin/ikiwiki


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
