# $NetBSD: Makefile,v 1.20 2014/05/29 23:37:47 wiz Exp $
#

DISTNAME=	XML-Stream-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Stream/
COMMENT=	XML::Stream provides you with access to XML Stream
LICENSE=	gnu-lgpl-v2

DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>0}:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/XML/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
