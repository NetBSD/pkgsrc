# $NetBSD: Makefile,v 1.2 2021/09/19 17:40:32 taca Exp $

DISTNAME=	aws-sigv4-1.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS Signature Version 4 library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-eventstream>=1<2:../../www/ruby-aws-eventstream

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
