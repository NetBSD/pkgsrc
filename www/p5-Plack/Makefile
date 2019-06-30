# $NetBSD: Makefile,v 1.48 2019/06/30 20:17:40 nia Exp $

DISTNAME=	Plack-1.0047
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Plack
COMMENT=	PSGI toolkit and servers
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-libwww>=5.814:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Message>=5.814:../../www/p5-HTTP-Message
DEPENDS+=	p5-URI>=1.59:../../www/p5-URI
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install>=0.04:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
#DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent
DEPENDS+=	p5-Devel-StackTrace>=1.23:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Devel-StackTrace-AsHTML>=0.11:../../devel/p5-Devel-StackTrace-AsHTML
DEPENDS+=	p5-Filesys-Notify-Simple-[0-9]*:../../devel/p5-Filesys-Notify-Simple
DEPENDS+=	p5-Hash-MultiValue>=0.05:../../devel/p5-Hash-MultiValue
DEPENDS+=	p5-HTTP-Entity-Parser>=0.17:../../www/p5-HTTP-Entity-Parser
DEPENDS+=	p5-Test-TCP>=2.00:../../net/p5-Test-TCP
DEPENDS+=	p5-Stream-Buffered>=0.02:../../devel/p5-Stream-Buffered
DEPENDS+=	p5-Apache-LogFormat-Compiler>=0.12:../../www/p5-Apache-LogFormat-Compiler
DEPENDS+=	p5-Cookie-Baker>=0.07:../../www/p5-Cookie-Baker
DEPENDS+=	p5-HTTP-Headers-Fast>=0.18:../../www/p5-HTTP-Headers-Fast

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
