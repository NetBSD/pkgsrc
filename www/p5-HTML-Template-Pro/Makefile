# $NetBSD: Makefile,v 1.2 2011/08/14 16:05:55 obache Exp $

DISTNAME=	HTML-Template-Pro-0.9504
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Template-Pro/
COMMENT=	Perl/XS module to use HTML Templates from CGI scripts
LICENSE=	${PERL5_LICENSE} OR gnu-lgpl-v2.1

DEPENDS+=	p5-JSON>=2.0:../../converters/p5-JSON

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/HTML/Template/Pro/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
