# $NetBSD: Makefile,v 1.1.1.1 2010/04/10 12:47:02 seb Exp $

DISTNAME=	Plack-0.9929
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack/
COMMENT=	PSGI toolkit and servers
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/.packlist

BUILD_DEPENDS+=	p5-Test-Simple>=0.88:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-TCP>=0.11:../../net/p5-Test-TCP
DEPENDS+=	p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Devel-StackTrace-AsHTML>=0.09:../../devel/p5-Devel-StackTrace-AsHTML
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Filesys-Notify-Simple-[0-9]*:../../devel/p5-Filesys-Notify-Simple
DEPENDS+=	p5-HTTP-Body>=1.06:../../www/p5-HTTP-Body
DEPENDS+=	p5-Hash-MultiValue>=0.05:../../devel/p5-Hash-MultiValue
DEPENDS+=	p5-libwww>=5.814:../../www/p5-libwww
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-URI>=1.36:../../www/p5-URI
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
