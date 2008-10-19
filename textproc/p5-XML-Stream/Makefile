# $NetBSD: Makefile,v 1.13 2008/10/19 19:18:59 he Exp $
#

DISTNAME=	XML-Stream-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~reatmon/XML-Stream-1.22/
COMMENT=	XML::Stream provides you with access to XML Stream

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Authen-SASL>0:../../security/p5-Authen-SASL
DEPENDS+=	p5-MIME-Base64>0:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/XML/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
