# $NetBSD: Makefile,v 1.16 2023/07/09 03:12:26 taca Exp $

DISTNAME=	aws-sdk-secretsmanager-1.79.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS SDK for Ruby - AWS Secrets Manager
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-core>=3.177<4:../../www/ruby-aws-sdk-core
#DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=1.1<2:../../www/ruby-aws-sigv4

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
