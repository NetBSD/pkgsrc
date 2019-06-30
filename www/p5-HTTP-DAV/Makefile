# $NetBSD: Makefile,v 1.37 2019/06/30 20:17:34 nia Exp $

DISTNAME=	HTTP-DAV-0.49
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-DAV
COMMENT=	HTTP::DAV interface and 'dave'
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=	bin/dave

DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

PERL5_PACKLIST=		auto/HTTP/DAV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
