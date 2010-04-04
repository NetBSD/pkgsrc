# $NetBSD: Makefile,v 1.48 2010/04/04 17:23:29 schmonz Exp $
#

DISTNAME=	ikiwiki_3.20100403
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/i/ikiwiki/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://ikiwiki.info/
COMMENT=	Wiki compiler
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-Markdown-[0-9]*:../../textproc/p5-Text-Markdown
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
DEPENDS+=	p5-CGI-Session-[0-9]*:../../www/p5-CGI-Session
DEPENDS+=	p5-CGI-FormBuilder>=3.05:../../www/p5-CGI-FormBuilder
DEPENDS+=	p5-Mail-Sendmail-[0-9]*:../../mail/p5-Mail-Sendmail
DEPENDS+=	p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-RPC-XML-[0-9]*:../../net/p5-RPC-XML
DEPENDS+=	p5-XML-Atom-[0-9]*:../../textproc/p5-XML-Atom
DEPENDS+=	p5-XML-Feed-[0-9]*:../../textproc/p5-XML-Feed
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-XML-RSS-[0-9]*:../../textproc/p5-XML-RSS
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext
#DEPENDS+=	po4a-[0-9]*:../../textproc/po4a

WRKSRC=			${WRKDIR}/${PKGBASE}
PERL5_PACKLIST=		auto/IkiWiki/.packlist
USE_LANGUAGES=		# none
USE_TOOLS+=		gmake msgfmt perl:run xgettext

REPLACE_PERL+=	ikiwiki-calendar ikiwiki-mass-rebuild
REPLACE_PERL+=	ikiwiki-transition ikiwiki-update-wikilist
REPLACE_PERL+=	ikiwiki-w3m.cgi ikiwiki.in gitremotes mdwn2man pm_filter
REPLACE_PERL+=	*.pm IkiWiki/*.pm IkiWiki/*/*.pm* *.setup */*.setup */*/*.setup
REPLACE_PERL+=	po/po2wiki t/*.t
REPLACE_PERL+=	plugins/externaldemo	# XXX not installed

REPLACE_PYTHON+=plugins/proxy.py plugins/pythondemo plugins/rst

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	post-patch
SUBST_FILES.sysconfdir=	ikiwiki-mass-rebuild ikiwiki-update-wikilist
SUBST_SED.sysconfdir+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	post-patch
SUBST_FILES.perlpath=	IkiWiki/Setup/Standard.pm
SUBST_SED.perlpath+=	-e 's,@PERL5@,${PERL5},g'

MAKE_FLAGS+=		W3M_CGI_BIN=${PREFIX:Q}/libexec/w3m/cgi-bin
MAKE_FLAGS+=		CONFIGDIR=${EGDIR:Q}
MAKE_FLAGS+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/auto.setup ${PKG_SYSCONFDIR}/auto.setup
CONF_FILES+=		${EGDIR}/auto-blog.setup ${PKG_SYSCONFDIR}/auto-blog.setup
CONF_FILES+=		${EGDIR}/wikilist ${PKG_SYSCONFDIR}/wikilist

.include "options.mk"

pre-configure:
	find ${WRKSRC} -type f -name '*.orig' -print | xargs rm -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
