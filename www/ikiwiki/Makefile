# $NetBSD: Makefile,v 1.83 2011/08/14 16:05:40 obache Exp $
#

DISTNAME=		ikiwiki_3.20110715
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		www textproc
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/i/ikiwiki/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://ikiwiki.info/
COMMENT=		Wiki compiler
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Text-Markdown-[0-9]*:../../textproc/p5-Text-Markdown
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
DEPENDS+=		p5-CGI-Session-[0-9]*:../../www/p5-CGI-Session
DEPENDS+=		p5-CGI-FormBuilder>=3.05:../../www/p5-CGI-FormBuilder
DEPENDS+=		p5-Mail-Sendmail-[0-9]*:../../mail/p5-Mail-Sendmail
DEPENDS+=		p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=		p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=		p5-RPC-XML-[0-9]*:../../net/p5-RPC-XML
DEPENDS+=		p5-XML-Atom-[0-9]*:../../textproc/p5-XML-Atom
DEPENDS+=		p5-XML-Feed-[0-9]*:../../textproc/p5-XML-Feed
DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=		p5-XML-RSS-[0-9]*:../../textproc/p5-XML-RSS
DEPENDS+=		p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=		p5-gettext-[0-9]*:../../devel/p5-gettext
DEPENDS+=		p5-YAML-[0-9]*:../../textproc/p5-YAML
#DEPENDS+=		po4a-[0-9]*:../../textproc/po4a

WRKSRC=			${WRKDIR}/${PKGBASE}
PERL5_PACKLIST=		auto/IkiWiki/.packlist
USE_LANGUAGES=		# none
USE_TOOLS+=		gmake msgfmt perl:run xgettext

REPLACE_PERL+=		Makefile.PL *.in *.cgi *.pm* */*.pm* */*/*.pm* */*.t
REPLACE_PERL+=		*.setup */*.setup */*/*.setup
REPLACE_PERL+=		ikiwiki-mass-rebuild ikiwiki-update-wikilist
REPLACE_PERL+=		gitremotes mdwn2man pm_filter po/po2wiki
REPLACE_PERL+=		plugins/externaldemo	# XXX not installed
# find . -type f -print | \
# perl -ne 'open(F, "<$_"); $l=<F>; print if $l =~ m|^#!/usr/bin/perl|'
REPLACE_PYTHON+=	plugins/proxy.py plugins/pythondemo plugins/rst

MAKE_FLAGS+=		W3M_CGI_BIN=${PREFIX:Q}/libexec/w3m/cgi-bin
MAKE_FLAGS+=		SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MAKE_FLAGS+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR:Q}

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
.for f in auto.setup auto-blog.setup wikilist
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

#SPECIAL_PERMS+=		${PREFIX}/bin/ikiwiki-update-wikilist ...

.include "options.mk"

pre-configure:
	find ${WRKSRC} -type f -name '*.orig' -print | xargs rm -f

.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
