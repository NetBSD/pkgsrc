# $NetBSD: Makefile,v 1.17 2012/09/11 13:21:52 wen Exp $

DISTNAME=	Plack-1.0003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack/
COMMENT=	PSGI toolkit and servers
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-libwww>=5.814:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Message>=5.814:../../www/p5-HTTP-Message
DEPENDS+=	p5-URI>=1.59:../../www/p5-URI
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent
DEPENDS+=	p5-Devel-StackTrace>=1.23:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Devel-StackTrace-AsHTML>=0.11:../../devel/p5-Devel-StackTrace-AsHTML
DEPENDS+=	p5-Filesys-Notify-Simple-[0-9]*:../../devel/p5-Filesys-Notify-Simple
DEPENDS+=	p5-Hash-MultiValue>=0.05:../../devel/p5-Hash-MultiValue
DEPENDS+=	p5-HTTP-Body>=1.06:../../www/p5-HTTP-Body
DEPENDS+=	p5-Test-TCP>=0.11:../../net/p5-Test-TCP

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
