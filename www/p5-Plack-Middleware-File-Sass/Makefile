# $NetBSD: Makefile,v 1.3 2011/08/14 16:06:05 obache Exp $

DISTNAME=	Plack-Middleware-File-Sass-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Middleware-File-Sass/
COMMENT=	Sass support for all Plack frameworks
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/File/Sass/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Text-Sass-[0-9]*:../../textproc/p5-Text-Sass

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
