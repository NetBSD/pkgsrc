# $NetBSD: Makefile,v 1.165 2019/08/11 13:24:20 wiz Exp $
#

DISTNAME=		ikiwiki_3.20190228.orig
PKGNAME=		${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=		3
CATEGORIES=		www textproc
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/i/ikiwiki/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://ikiwiki.info/
COMMENT=		Flexible static site generator with dynamic features
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-Text-Markdown-Discount-[0-9]*:../../textproc/p5-Text-Markdown-Discount
DEPENDS+=		p5-URI>=1.36:../../www/p5-URI
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
DEPENDS+=		p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=		p5-Mail-Sendmail-[0-9]*:../../mail/p5-Mail-Sendmail
DEPENDS+=		p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=		p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=		p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=		p5-RPC-XML-[0-9]*:../../net/p5-RPC-XML
DEPENDS+=		p5-XML-Atom-[0-9]*:../../textproc/p5-XML-Atom
DEPENDS+=		p5-XML-Feed-[0-9]*:../../textproc/p5-XML-Feed
DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=		p5-XML-RSS-[0-9]*:../../textproc/p5-XML-RSS
DEPENDS+=		p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=		p5-gettext-[0-9]*:../../devel/p5-gettext
DEPENDS+=		p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
DEPENDS+=		p5-LWPx-ParanoidAgent-[0-9]*:../../www/p5-LWPx-ParanoidAgent

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/ikiwiki-/IkiWiki-/}
PERL5_PACKLIST=		auto/IkiWiki/.packlist
USE_LANGUAGES=		c
USE_TOOLS+=		gmake msgfmt perl:run xgettext

REPLACE_PYTHON+=	plugins/proxy.py plugins/pythondemo plugins/rst
REPLACE_PERL+=		pm_filter

MAKE_FLAGS+=		W3M_CGI_BIN=${PREFIX:Q}/libexec/w3m/cgi-bin
MAKE_FLAGS+=		SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MAKE_FLAGS+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR:Q}

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
.for f in auto.setup auto-blog.setup wikilist
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

TEST_TARGET=		test

maintainer-find-default-perl-shebangs-not-substed:
	cd ${WRKSRC} && \
	find . -type f -print | \
	perl -ne 'open(F, "<$$_"); $$l=<F>; print if $$l =~ m|^#!/usr/bin/perl|'

.include "options.mk"

pre-configure:
	find ${WRKSRC} -type f -name '*.orig' -print | xargs rm -f

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
TOOLS_PLATFORM.find=	# empty, to force GNU find from pkgsrc findutils
.endif

.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
