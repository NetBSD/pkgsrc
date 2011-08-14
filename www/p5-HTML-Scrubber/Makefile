# $NetBSD: Makefile,v 1.12 2011/08/14 16:05:54 obache Exp $
#

DISTNAME=	HTML-Scrubber-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension for scrubbing/sanitizing html

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-HTML-Parser>=3:../../www/p5-HTML-Parser

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Scrubber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
