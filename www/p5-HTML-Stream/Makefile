# $NetBSD: Makefile,v 1.4 2008/08/05 11:22:13 he Exp $

DISTNAME=	HTML-Stream-1.59
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Stream/
COMMENT=	Perl5 HTML output stream class, and some markup utilities

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/HTML/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
