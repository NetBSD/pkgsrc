# $NetBSD: Makefile,v 1.18 2018/08/22 09:47:47 wiz Exp $

DISTNAME=	LWP-Authen-Negotiate-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://perlgssapi.sourceforge.net/
COMMENT=	Library for enabling GSSAPI authentication in LWP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-GSSAPI-[0-9]*:../../security/p5-GSSAPI
#DEPENDS+=	{perl>=5.10,p5-MIME-Base64>=2.12}:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/LWP/Authen/Negotiate/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
