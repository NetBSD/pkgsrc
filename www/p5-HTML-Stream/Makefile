# $NetBSD: Makefile,v 1.9 2012/10/03 21:58:45 wiz Exp $

DISTNAME=	HTML-Stream-1.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Stream/
COMMENT=	Perl5 HTML output stream class, and some markup utilities

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/HTML/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
