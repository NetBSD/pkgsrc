# $NetBSD: Makefile,v 1.4 2012/12/12 11:49:53 wiz Exp $
#

DISTNAME=	HTTP-Server-EV-0.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-EV/
COMMENT=	Asynchronous HTTP server using EV event loop
LICENSE=	${PERL5_LICENSE}

PERL5_REQD+=	5.8

DEPENDS+=	{perl>=5.10.1,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils # List::Util::XS
DEPENDS+=	p5-File-Util-[0-9]*:../../devel/p5-File-Util
DEPENDS+=	p5-Guard-[0-9]*:../../devel/p5-Guard
DEPENDS+=	p5-AnyEvent-HTTP-[0-9]*:../../www/p5-AnyEvent-HTTP
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

PERL5_PACKLIST=		auto/HTTP/Server/EV/.packlist

.include "../../devel/p5-EV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
